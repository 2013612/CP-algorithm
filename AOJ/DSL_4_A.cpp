#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;

int n, cc[4003][4003];
vector<int> x, y;
long long ans;
ppiipii r[4003];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		r[i] = {{a, b}, {c, d}};
		x.push_back(a);
		x.push_back(c);
		y.push_back(b);
		y.push_back(d);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	for (int i = 0; i < n; i++) {
		int x1 = lower_bound(x.begin(), x.end(), r[i].first.first) - x.begin();
		int y1 = lower_bound(y.begin(), y.end(), r[i].first.second) - y.begin();
		int x2 = lower_bound(x.begin(), x.end(), r[i].second.first) - x.begin();
		int y2 = lower_bound(y.begin(), y.end(), r[i].second.second) - y.begin();
		cc[x1][y1]++;
		cc[x1][y2]--;
		cc[x2][y1]--;
		cc[x2][y2]++;
	}
	for (int i = 0; i < x.size(); i++) {
		for (int j = 1; j < y.size(); j++) {
			cc[i][j] += cc[i][j - 1];
		}
	}
	for (int i = 0; i < y.size(); i++) {
		for (int j = 1; j < x.size(); j++) {
			cc[j][i] += cc[j - 1][i];
		}
	}
	for (int i = 0; i < x.size() - 1; i++) {
		for (int j = 0; j < y.size() - 1; j++) {
			if (cc[i][j] > 0) {
				ans += 1ll * (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
