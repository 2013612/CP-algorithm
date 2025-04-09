#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int N, ans;
pii a[200006];

bool f(pii a, pii b) {
	if (1ll * (a.second - 1) * b.first == 1ll * a.first * (b.second - 1)) {
		return 1ll * a.second * (b.first - 1) < 1ll * (a.first - 1) * b.second;
	}
	return 1ll * (a.second - 1) * b.first > 1ll * a.first * (b.second - 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int b, c;
		scanf("%d %d", &b, &c);
		a[i] = {b, c};
	}
	sort(a, a + N, f);
//	printf("\n");
//	for (int i = 0; i < N; i++) {
//		printf("%d %d\n", a[i].first, a[i].second);
//	}
	pii cur = {0, 2e9};
	for (int i = 0; i < N; i++) {
		if (1ll * a[i].second * cur.first <= 1ll * (cur.second - 1) * (a[i].first - 1)) {
			//printf("%d\n", i);
			ans++;
			cur = a[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
