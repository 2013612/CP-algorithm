#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> ppiipii;

int n, m, q, a[200006];
bool ans[200006];
pipii e[200006];
ppiipii f[200006];

int find(int x) {
	if (a[x] == x) {
		return x;
	}
	return a[x] = find(a[x]);
}

void merge(int x, int y) {
	a[find(x)] = find(y);
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[i] = {c, {a, b}};
	}
	sort(e, e + m);
	for (int i = 0; i < q; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		f[i] = {{w, i}, {u, v}};
	}
	sort(f, f + q);
	for (int i = 0, j = 0; i < m && j < q; ) {
		if (f[j].first.first < e[i].first) {
			if (find(f[j].second.first) != find(f[j].second.second)) {
				ans[f[j].first.second] = true;
			}
			j++;
		} else {
			merge(e[i].second.first, e[i].second.second);
			i++;
		}
	}
	for (int i = 0; i < q; i++) {
		if (ans[i]) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	} 
	return 0;
}
