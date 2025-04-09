#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[100006];
long long ans, cost[1004];
char c[10];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < 200; i++) {
		cost[i] = 1e9;
	}
	for (int i = 0; i < N; i++) {
		int num = 0;
		scanf("%d", &a[i]);
		scanf("%s", c);
		string s = c;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'A') {
				num += 1;
			} else if (s[j] == 'B') {
				num += 10;
			} else {
				num += 100;
			}
		}
		cost[num] = min(cost[num], 1ll*a[i]);
	}
	ans = cost[1] + cost [10] + cost[100];
	ans = min(ans, cost[1] + cost[110]);
	ans = min(ans, cost[10] + cost[101]);
	ans = min(ans, cost[100] + cost[11]);
	ans = min(ans, cost[11] + cost[110]);
	ans = min(ans, cost[11] + cost[101]);
	ans = min(ans, cost[101] + cost[110]);
	ans = min(ans, cost[111]);
	if (ans > 1e8) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
