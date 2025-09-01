#include<bits/stdc++.h>
using namespace std;

long long r1, c1, r2, c2, n, m, l, ans;
pair<string, long long> s[100005], t[100005];

int main() {
	scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
	scanf("%lld %lld %lld", &n, &m, &l);
	for (int i = 0; i < m; i++) {
		cin >> s[i].first >> s[i].second;
	}

	for (int i = 0; i < l; i++) {
		cin >> t[i].first >> t[i].second;
	}

	int j = 0, k = 0;
	while (j < m && k < l) {
		long long step = min(s[j].second, t[k].second);
		if (r1 == r2 && c1 == c2) {
			if (s[j].first == t[k].first) {
				ans += step;
			}
		} else if (r1 == r2) {
			if ((abs(c1 - c2) % 2 == 0) && abs(c2 - c1) <= 2 * step) {
				if (c1 < c2) {
					if (s[j].first == "R" && t[k].first == "L") {
						ans++;
					}
				} else {
					if (s[j].first == "L" && t[k].first == "R") {
						ans++;
					}
				}
			}
		} else if (c1 == c2) {
			if ((abs(r1 - r2) % 2 == 0) && abs(r2 - r1) <= 2 * step) {
				if (r1 < r2) {
					if (s[j].first == "D" && t[k].first == "U") {
						ans++;
					}
				} else {
					if (s[j].first == "U" && t[k].first == "D") {
						ans++;
					}
				}
			}
		} else if (abs(r1 - r2) == abs(c1 - c2) && abs(r1 - r2) <= step) {
			if (r1 < r2 && c1 < c2) {
				if (s[j].first == "D" && t[k].first == "L") {
					ans++;
				} else if (s[j].first == "R" && t[k].first == "U") {
					ans++;
				}
			} else if (r1 < r2 && c1 > c2) {
				if (s[j].first == "D" && t[k].first == "R") {
					ans++;
				} else if (s[j].first == "L" && t[k].first == "U") {
					ans++;
				}
			} else if (r1 > r2 && c1 < c2) {
				if (s[j].first == "U" && t[k].first == "L") {
					ans++;
				} else if (s[j].first == "R" && t[k].first == "D") {
					ans++;
				}
			} else if (r1 > r2 && c1 > c2) {
				if (s[j].first == "U" && t[k].first == "R") {
					ans++;
				} else if (s[j].first == "L" && t[k].first == "D") {
					ans++;
				}
			} 
		}

		if (s[j].first == "U") {
			r1 -= step;
		} else if (s[j].first == "D") {
			r1 += step;
		} else if (s[j].first == "L") {
			c1 -= step;
		} else if (s[j].first == "R") {
			c1 += step;
		}

		s[j].second -= step;
		if (s[j].second <= 0) {
			j++;
		}

		if (t[k].first == "U") {
			r2 -= step;
		} else if (t[k].first == "D") {
			r2 += step;
		} else if (t[k].first == "L") {
			c2 -= step;
		} else if (t[k].first == "R") {
			c2 += step;
		}

		t[k].second -= step;
		if (t[k].second <= 0) {
			k++;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}