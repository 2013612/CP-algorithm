#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, ans, s[100006];
pii x[100006], y[100006];
vector<pipii> e;

int find(int a) {
	if (s[a] == a) {
		return a;
	} else {
		return s[a] = find(s[a]);
	}
}

void merge(int a, int b) {
	s[find(a)] = find(b);
}

bool same(int a, int b) {
	return find(a) == find(b);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		x[i] = {a, i};
		y[i] = {b, i};
		s[i] = i;
	}
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 1; i < n; i++) {
		e.push_back({x[i].first - x[i - 1].first, {x[i - 1].second, x[i].second}});
		e.push_back({y[i].first - y[i - 1].first, {y[i - 1].second, y[i].second}});
	}
	sort(e.begin(), e.end());
	for (auto x : e) {
		if (n == 1) {
			break;
		}
		if (same(x.second.first, x.second.second)) {
			continue;
		}
		ans += x.first;
		merge(x.second.first, x.second.second);
		n--;
	}
	printf("%d\n", ans);
	return 0;
}
