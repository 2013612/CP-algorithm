#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, ans;
vector<pipii> a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (i % 2 == 0) {
			if (a.empty() || a.back().first != t) {
				a.push_back({t, {i, i}});
			} else {
				a.back().second.second = i;
			}
		} else {
			while (!a.empty() && a.back().first != t) {
				a.pop_back();
			}
			if (a.empty()) {
				a.push_back({t, {0, i}});
			} else {
				a.back().second.second = i;
			}
		}
	}
	for (auto x:a) {
		if (x.first == 0) {
			ans += x.second.second - x.second.first + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
