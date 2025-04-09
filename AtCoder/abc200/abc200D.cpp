#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int N, a[203], dp[203][203];
vector<int> u, v, zero;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		a[i] = a[i] % 200;
		if (a[i] == 0) {
			zero.push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		dp[i][a[i]]++;
		for (int j = 0; j < 200; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][(j + a[i]) % 200] += dp[i - 1][j];
		}
	}
	
	if (zero.size() > 0) {
		printf("Yes\n");
		if (zero.size() >= 2) {
			printf("1 %d\n", zero[0]);
			printf("2 %d %d\n", zero[0], zero[1]);
			return 0;
		}
		for (int i = 1; i <= N; i++) {
			if (a[i] != 0) {
				printf("1 %d\n", i);
				printf("2 %d %d\n", min(i, zero[0]), max(i, zero[0]));
				return 0;
			}
		}
	}
	
	for (int i = 1; i < 200; i++) {
		if (dp[i][0] > 0) {
			vector<int> temp(1, i);
			int temp2 = 200 - a[i];
			for (int j = i - 1; j >= 0; j--) {
				if (temp2 == 0) {
					break;
				}
				if (dp[j - 1][temp2] == 0) {
					temp.push_back(j);
					temp2 = (temp2 - a[j] + 200) % 200;
				}
			}
			sort(temp.begin(), temp.end());
			for (int j = 1; j <= 200; j++) {
				if (!binary_search(temp.begin(), temp.end(), j)) {
					printf("1 %d\n", j);
					printf("%d", temp.size());
					for (auto x:temp) {
						printf(" %d", x);
					}
					printf("\n");
					return 0;
				}
			}
		}
	}
	
	int init = -1;
	int first = -1;
	int second = -1;
	for (int i = 1; i < 200; i++) {
		if (dp[N][i] >= 2) {
			init = first = second = i;
			break;
		}
	}
	
	if (first == -1) {
		printf("No\n");
		return 0;
	}
	
	printf("Yes\n");
	for (int i = N - 1; i >= 0; i--) {
		if (first == second) {
			if (dp[i][first] == 0) {
				u.push_back(i + 1);
				v.push_back(i + 1);
				first = (first - a[i + 1] + 200) % 200;
				second = (second - a[i + 1] + 200) % 200;
			} else if (dp[i][first] == 1) {
				v.push_back(i + 1);
				second = (second - a[i + 1] + 200) % 200;
			}
		} else {
			if (first != 0 && dp[i][first] == 0 && dp[i + 1][first] != 0) {
				u.push_back(i + 1);
				first = (first - a[i + 1] + 200) % 200;
			}
			
			if (second != 0 && dp[i][second] == 0 && dp[i + 1][second] != 0) {
				v.push_back(i + 1);
				second = (second - a[i + 1] + 200) % 200;
			}
		}
	}
	
	printf("%d", u.size());
	for (int i = u.size() - 1; i >= 0; i--) {
		printf(" %d", u[i]);
	}
	printf("\n");
	printf("%d", v.size());
	for (int i = v.size() - 1; i >= 0; i--) {
		printf(" %d", v[i]);
	}
	printf("\n");
	return 0;
}
