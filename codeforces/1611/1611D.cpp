#include<iostream>
using namespace std;

int t, n, b[200006], p[200006], d[200006], r[200006];
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		bool can = true;
		int dis = 1;
		for (int i = 0; i < n + 10; i++) {
			d[i] = 2e9;
			r[i] = 2e9;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			if (b[i] == i) {
				d[i] = 0;
				r[i] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				if (d[p[i]] != 0) {
					can = false;
					break;
				}
				continue;
			} 
			
			if (r[b[p[i]]] > 1e9) {
				can = false;
				break;
			} else {
				r[p[i]] = dis;
				d[p[i]] = dis - r[b[p[i]]];
				dis++;
			}
		}
		if (!can) {
			printf("-1\n");
		} else {
			for (int i = 1; i <= n; i++) {
				printf("%d ", d[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
