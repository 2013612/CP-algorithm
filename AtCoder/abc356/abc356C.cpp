#include<iostream>
using namespace std;

int n, m, k, c[103], a[103][103], ans, b[20];
bool r[103];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &c[i]);
		for (int j = 0; j < c[i]; j++) {
			scanf("%d", &a[i][j]);
		}
		string s;
		cin >> s;
		r[i] = s == "o";
	}
	
	for (int i = 0; i < (1 << n); i++) {
		int t = i;
		for (int j = 1; j <= n; j++) {
			if (t & 1) {
				b[j] = 1;
			} else {
				b[j] = 0;
			}
			t >>= 1;
		}
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int u = 0; u < c[j]; u++) {
				cnt += b[a[j][u]];
			}
			
			if (cnt >= k != r[j]) {
				break;
			}
			
			if (j == m - 1) {
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}