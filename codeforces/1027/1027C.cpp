#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, m, p, a[100006];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int ans = 0;
		int maxi = 0;
		int g, h;
		g = 1;
		h = 20000;
		int maxii = 0;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &p);
			a[p]++;
			maxii = max(maxii, p);
			if (a[p] >= 2) {
				maxi = max(maxi, p);
			}
			if (a[p] >= 4) {
				ans = p;
				break;
			}
		}
		if (ans > 0) {
			printf("%d %d %d %d\n", ans, ans, ans, ans);
		} else {
			for (int j = maxi - 1, k = maxi; j >= 1; j--) {
				if (a[k] >= 2 && a[j] >= 2) {
					if (1ll*(g*g + h*h)*k*j > 1ll*(k*k + j*j)*g*h) {
						g = j;
						h = k;
					}
					k = j;
				}
			}
			printf("%d %d %d %d\n", g, g, h, h);
		}
		for (int j = 1; j <= maxii; j++) {
			a[j] = 0;
		}
	}
	return 0;
}
