#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int, int>> pipii;

int n, m, k, s[100006], ans;
pipii e[100006];

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

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		s[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = {c, {a, b}};
	}
	sort(e, e + m);
	for (int i = 0; n > k && i < m; i++) {
		if (find(e[i].second.first) == find(e[i].second.second)) {
			continue;
		}
		k++;
		ans += e[i].first;
		merge(e[i].second.first, e[i].second.second);
	}
	printf("%d\n", ans);
	return 0;
}
