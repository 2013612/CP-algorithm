#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
long long ans;
pair<int, int> a[200006];

bool f(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, f);
	
	int l = 1, r = 1;
	int i = 0;
	
	while (r <= m + 1) {
		if (i == n) {
			ans += 1ll * (m + 1 + r - 2 * l) * (m - r + 2) / 2;
			break;
		}
		
		if (r <= a[i].second) {
			ans += r - l;
			r++;
		} else {
			l = max(l, a[i].first + 1);
			i++;
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}