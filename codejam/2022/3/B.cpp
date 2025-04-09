#include<iostream>
#include<set>
using namespace std;

int a[100006], b[100006], h[100006], color[100006];

bool f(int i) {
	return color[i] == 0 || (color[i] >= a[i] && color[i] <= b[i]);
}

void solve() {
	int n, c, ans = 0;
	scanf("%d %d", &n, &c);
	
	for (int i = 1; i <= c; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= c; j++) {
			color[j] = 0;
		}
		set<int> check;
		for (int j = 0; j < i - 1; j++) {
			color[h[j]]++;
			if (!f(h[j])) {
				check.insert(h[j]);
			}
		}
		for (int j = i - 1; j < n + i - 1; j++) {
			int k = j % n;
			color[h[k]]++;
			if (!f(h[k])) {
				check.insert(h[k]);
			}
			set<int> temp;
			for (auto x : check) {
				if (f(x)) {
					temp.insert(x);
				} else {
					break;
				}
			}
			for (auto x : temp) {
				check.erase(x);
			}
			if (check.empty()) {
				ans++;
			}
			int p = (j - (i - 1) + n) % n;
			color[h[p]]--;
			if (!f(h[p])) {
				check.insert(h[p]);
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}