#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int N, M, ans, Q;
bool a[200006];
map<int, int> m[200006];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		m[u][v] = 1;
		m[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		m[i][i] = 1;
		if (m[i].upper_bound(i) == m[i].end()) {
			a[i] = true;
			ans++;
		}
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			m[u][v] = 1;
			m[v][u] = 1;
			if (a[u]) {
				if (v > u) {
					a[u] = false;
					ans--;
				}
			}
			if (a[v]) {
				if (u > v) {
					a[v] = false;
					ans--;
				}
			}
		} else if (t == 2) {
			int u, v;
			scanf("%d %d", &u, &v);
			m[u].erase(v);
			m[v].erase(u);
			if (!a[u]) {
				if (m[u].upper_bound(u) == m[u].end()) {
					a[u] = true;
					ans++;
				}
			}
			if (!a[v]) {
				if (m[v].upper_bound(v) == m[v].end()) {
					a[v] = true;
					ans++;
				}
			}
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
