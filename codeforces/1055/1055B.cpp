#include<iostream>
using namespace std;

int N, M, L, ans;
long long a[100006];
int main() {
	scanf("%d %d %d", &N, &M, &L);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	if (a[0] > L) {
		ans++;
	}
	for (int i = 0; i < N - 1; i++) {
		if (a[i] <= L && a[i + 1] > L) {
			ans++;
		}
	}
	for (int i = 0; i < M; i++) {
		int T;
		scanf("%d", &T);
		if (T == 0) {
			printf("%d\n", ans);
		} else {
			int p, d;
			scanf("%d %d", &p, &d);
			a[p - 1] = a[p - 1] + d;
			if (a[p - 1] > L && a[p - 1] <= L + d) {
				if (p == 1) {
					if (a[p] <= L) {
						ans++;
					}
					continue;
				}
				if (p == N) {
					if (a[p - 2] <= L) {
						ans++;
					}
					continue;
				}
				if (a[p] > L && a[p - 2] > L) {
					ans--;
					continue;
				}
				if (a[p] <= L && a[p - 2] <= L) {
					ans++;
					continue;
				}
			}
		}
	}
	return 0;
}
