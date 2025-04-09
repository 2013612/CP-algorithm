#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, w;
long long ans;
pii a[300006];
int main() {
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, greater<pii>());
	for (int i = 0; i < n; i++) {
		if (w == 0) {
			break;
		}
		ans += 1ll * a[i].first * min(w, a[i].second);
		w -= min(w, a[i].second);
	}
	printf("%lld\n", ans);
	return 0;
}
