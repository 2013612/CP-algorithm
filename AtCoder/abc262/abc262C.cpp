#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans, a[500006];
long long cnt;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) {
			cnt++;
		} else if (a[i] > i) {
			if (a[a[i]] == i) {
				ans++;
			}
		}
	}
	printf("%lld\n", cnt * (cnt - 1) / 2 + ans);
	return 0;
}