#include<iostream>
#include<algorithm>
using namespace std;

int N, a[100005], b[100005], c[100005];
long long ans, couB[100005];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &c[i]);
	}
	sort(a, a + N);
	sort(b, b + N);
	sort(c, c + N);
	for (int i = 0; i < N; i++) {
		int posC = upper_bound(c, c + N, b[i]) - c;
		couB[i + 1] = couB[i] + N - posC;
	}
	for (int i = 0; i < N; i++) {
		int posB = upper_bound(b, b + N, a[i]) - b;
		ans += couB[N] - couB[posB];
	}
	printf("%lld\n", ans);
	return 0;
}
