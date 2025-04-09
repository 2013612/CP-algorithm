#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int N, a[2004], b[2004], ans, sum;
unordered_map<int, int> subseq[103];
int main() {
	scanf("%d", &N);
	for (int j = 0; j < N; j++) {
		scanf("%d", &a[j]);
		b[j] = a[j];
		sum += a[j];
	}
	if (sum & 1) {
		printf("0\n");
		return 0;
	}
	sort(b, b + N);
	//subseq[0][b[0]] = 1;
	for (int i = 1; i <= N; i++) {
		subseq[i][b[i - 1]] = 1;
		for (auto x:subseq[i - 1]) {
			//printf("%d %d %d\n", i, x.first, x.second);
			if (subseq[i].count(x.first) != 0) {
				subseq[i][x.first] += x.second;
			} else {
				subseq[i][x.first] = x.second;
			}
			if (subseq[i].count(x.first + b[i - 1]) != 0) {
				subseq[i][x.first + b[i - 1]] += x.second;
			} else {
				subseq[i][x.first + b[i - 1]] = x.second;
			}
		}
	}
//	for (int i = 0; i <= N; i++) {
//		printf("%d\n", i);
//		for (auto x:subseq[i]) {
//			printf("%d %d\n", x.first, x.second);
//		}
//		printf("\n");
//	}
	if (!subseq[N][sum / 2]) {
		printf("0\n");
		return 0;
	}
	int mod = 2;
	while (true) {
		for (int i = 0; i < N; i++) {
			if (a[i] % mod != 0) {
				printf("1\n");
				printf("%d\n", i + 1);
				return 0;
			}
		}
		mod *= 2;
	}
	return 0;
}
