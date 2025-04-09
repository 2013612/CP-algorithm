#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, a[1000006], ans, b[1000006], c[1000006];

int main() {
	scanf("%d %d", &n, &q);
	
	for (int i = 0; i < n; i++) {
		a[i] = i;
		b[i] = i;
		c[i] = i;
	}
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		
		if (t == 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			
			a[u] = c[v];
		} else if (t == 2) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--;
			v--;
			
			int nestu = c[u];
			int nestv = c[v];
			
			b[nestu] = v;
			b[nestv] = u;
			c[v] = nestu;
			c[u] = nestv;
		} else {
			int u;
			scanf("%d", &u);
			u--;
			printf("%d\n", b[a[u]] + 1);
		}
		
//		for (int j = 0; j < n; j++) {
//			printf("%d ", a[j]);
//		}
//		printf("\n");
	}
	return 0;
}