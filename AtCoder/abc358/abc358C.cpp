#include<iostream>
using namespace std;

int main() {
	int n, m, a[20];
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[i] = 0;
		for (int j = 0; j < m; j++) {
			a[i] = (a[i] << 1) + (s[j] == 'o');
		}
	}
	
	int ans = 1e9;
	
	for (int i = 1; i < (1 << n); i++) {
		int cnt = 0;
		int k = i;
		int f = 0;
		for (int j = n - 1; j >= 0 && k > 0; j--) {
			if (k & 1) {
				f |= a[j];
				cnt++;
			}
			
			k >>= 1;
		}
		
		
		if (f == (1 << m) - 1) {
			ans = min(ans, cnt);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}