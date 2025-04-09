#include<iostream>
using namespace std;
const int M = 1e5;

int n, m, pre[100006];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n - 1; i++) {
		int a;
		scanf("%d", &a);
		pre[i] = pre[i - 1] + a;
	}
	int now = 0;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		ans = (ans + abs(pre[now + a] - pre[now])) % M;
		now += a;
	}
	printf("%d\n", ans);
	return 0;
}
