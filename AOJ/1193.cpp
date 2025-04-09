#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> a[5];
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			a[i].clear();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				int t;
				scanf("%d", &t);
				a[j].push_back(t);
			}
		}
		for (int i = 0; i < 5; i++) {
			reverse(a[i].begin(), a[i].end());
		}
		bool con = true;
		while (con) {
			con = false;
			for (int i = 0; i < n; i++) {
				int cnt = 0;
				int now = -1;
				for (int j = 0; j < 5; j++) {
					if (a[j].size() > i && now == a[j][i]) {
						cnt++;
					} else {
						if (cnt >= 3) {
							ans += cnt * now;
							for (int k = cnt; k > 0; k--) {
								a[j - k][i] = -1;
							}
							con = true;
							cnt = 0;
							break;
						}
						if (a[j].size() <= i) {
							cnt = 0;
							now = -1;
						} else {
							cnt = 1;
							now = a[j][i];
						}
					}
				}
				if (cnt >= 3) {
					ans += cnt * now;
					for (int k = cnt; k > 0; k--) {
						a[5 - k][i] = -1;
					}
					con = true;
				}
			}
			vector<int> b[5];
			for (int i = 0; i < 5; i++) {
				for (auto x:a[i]) {
					if (x > 0) {
						b[i].push_back(x);
					}
				}
				a[i] = b[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
