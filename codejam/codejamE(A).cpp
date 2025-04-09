#include<iostream>
#include<algorithm>
using namespace std;

int T, K, N, a[10005];
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		sort(a, a + N);
		int ans = 0;
		int day = 0;
		for (int j = 0; j < N; j++) {
			if (a[j] > day) {
				ans++;
				if (ans % K == 0) {
					day++;
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	
	return 0;
}
