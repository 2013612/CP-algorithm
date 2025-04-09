#include<iostream>
#include<set>
#include<cmath>
using namespace std;
typedef pair<int, int> pii;

set<pii> c, w;
void wrong(int r) {
	for (int i = 0; i <= r; i++) {
		double y = sqrt(r * r - i * i);
		y = round(y - 1e-9);
		w.insert({i, (int) y});
		w.insert({(int) y, i});
	}
//	for (auto [x, y]: w) {
//		printf("!%d %d\n", x, y);
//	}
}

void correct(int r) {
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= r; j++) {
			double t = sqrt(i * i + j * j);
			if (round(t - 1e-9) <= r) {
				c.insert({i, j});
			}
		}
	}
//	for (auto [x, y]: c) {
//		printf("@%d %d\n", x, y);
//	}
} 

void solve() {
	int n;
	scanf("%d", &n);
	c.clear();
	w.clear();
	for (int i = 0; i <= n; i++) {
		wrong(i);
	}
	correct(n);
	printf("%d\n", (c.size() - w.size()) * 4);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}