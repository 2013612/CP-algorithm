#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
typedef pair<double, pair<int, int>> pdpii;

int n, s[103];
double x[103], y[103], z[103], r[103];

int find(int a) {
	return s[a] == a ? a : s[a] = find(s[a]);
}

void merge(int a, int b) {
	s[find(a)] = find(b);
}

double dis(int i, int j) {
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	double dz = z[i] - z[j];
	return sqrt(dx * dx + dy * dy + dz * dz) - r[i] - r[j]; 
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		int t = n;
		for (int i = 0; i < n; i++) {
			scanf("%lf %lf %lf %lf", &x[i], &y[i], &z[i], &r[i]);
			s[i] = i;
		}
		vector<pdpii> e;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (find(i) == find(j)) {
					continue;
				}
				double d = dis(i, j);
				if (d < 1e-6) {
					merge(i, j);
					t--;
				} else {
					e.push_back({d, {i, j}});
				}
			}
		}
		sort(e.begin(), e.end());
		double ans = 0;
		for (int i = 0; t > 1; i++) {
			if (find(e[i].second.first) == find(e[i].second.second)) {
				continue;
			}
			t--;
			ans += e[i].first;
			merge(e[i].second.first, e[i].second.second);
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
