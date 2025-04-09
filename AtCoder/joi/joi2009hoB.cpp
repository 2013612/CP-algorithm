#include<iostream>
#include<algorithm>
using namespace std;

int D, N, M;
long long a[100005], ans;
int main() {
	scanf("%d %d %d", &D, &N, &M);
	for (int i = 1; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + N);
	a[N] = D;
	for (int i = 0; i < M; i++) {
		int q;
		scanf("%d", &q);
		int left = 0;
		int right = N;
		while (left < right) {
			int mid = (left + right) / 2;
			if (q <= a[mid]) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		if (right != 0) {
			ans += min(a[right] - q, q - a[right - 1]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
