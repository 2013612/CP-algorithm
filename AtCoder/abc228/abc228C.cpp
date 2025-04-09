#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[100006], K, p[100006];
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int b, c, d;
		scanf("%d %d %d", &b, &c, &d);
		a[i] = b + c + d;
		p[i] = a[i];
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		int pos = upper_bound(p, p + N, a[i] + 300) - p;
		if (K >= N - pos + 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
