#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int h, w, k, ans;
vector<int> a[103];
int main() {
	scanf("%d %d %d", &h, &w, &k);
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			a[j].push_back(s[j] - '0');
		}
	}
	for (int i = 0; i < w; i++) {
		reverse(a[i].begin(), a[i].end());
	}
	for (int q = 0; q < h; q++) {
		for (int i = 0; i < w; i++) {
			vector<int> b[w];
			for (int j = 0; j < w; j++) {
				b[j] = a[j];
				if (i == j) {
					b[j].erase(b[j].begin() + q);
				}
			}
			int mark = 0;
			int mul = 1;
			bool con = true;
			while (con) {
				con = false;
				for (int j = 0; j < h; j++) {
					int cnt = 0;
					int now = -1;
					for (int l = 0; l < w; l++) {
						if (b[l].size() > j && b[l][j] == now) {
							cnt++;
						} else {
							if (cnt >= k) {
								con = true;
								mark += mul * cnt * now;
								for (int p = cnt; p > 0; p--) {
									b[l - p][j] = -1;
								}
								cnt = 0;
							}
							if (b[l].size() <= j) {
								cnt = 0;
								now = -1;
							} else {
								cnt = 1;
								now = b[l][j];
							}
						}
					}
					if (cnt >= k) {
						con = true;
						mark += mul * cnt * now;
						for (int p = cnt; p > 0; p--) {
							b[w - p][j] = -1;
						}
					}
				}
				vector<int> c[w];
				for (int l = 0; l < w; l++) {
					for (auto x:b[l]) {
						if (x > 0) {
							c[l].push_back(x);
						}
					}
					b[l] = c[l];
				}
				mul *= 2;
			}
			ans = max(ans, mark);
		}
	}
	printf("%d\n", ans);
	return 0;
}
