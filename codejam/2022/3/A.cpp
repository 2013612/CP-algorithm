#include<iostream>
using namespace std;

int main() {
	int t, n, k;
	scanf("%d %d %d", &t, &n, &k);
	while (t-- > 0) {
		int s = 0;
		while (s == 0) {
			int a[103], out[103], b[103];
			for (int i = 1; i <= n; i++) {
				out[i] = -1;
				scanf("%d", &a[i]);
				b[a[i]] = i;
			}
			int c = 1;
			for (int i = 1; i <= n; i++) {
				if (out[i] > 0) {
					continue;
				}
				
				out[i] = c;
				if (a[i] != i) {
					if (b[i] < i) {
						out[i] = out[b[i]];
					} else {
						out[b[i]] = c;
					}
				}
				//printf("%d %d %d\n", i, b[i], c);
				
				c++;
			}
			for (int i = 1; i <= n; i++) {
				printf("%d%c", out[i], i == n ? '\n' : ' ');
			}
			fflush(stdout);
			scanf("%d", &s);
		}
		if (s == -1) {
			break;
		}
	}
	return 0;
}