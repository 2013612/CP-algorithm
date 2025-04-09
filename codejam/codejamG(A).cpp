#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, a[10005], ans;
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		ans = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		sort(a, a + N);
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (a[j] != 0) {
				break;
			}
			count++;
		}
		ans += count*(count - 1)/2*(N - count);
		for (int j = 0; j < N - 2; j++) {
			for (int k = j + 1; k < N - 1; k++) {
				if (binary_search(a + k + 1, a + N, a[j]*a[k])) {
					ans += upper_bound(a + k + 1, a + N, 1ll*a[j]*a[k]) - lower_bound(a + k + 1, a + N, 1ll*a[j]*a[k]);
				}
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
