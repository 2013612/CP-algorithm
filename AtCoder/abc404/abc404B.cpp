#include<iostream>
using namespace std;

int n, ans = 1e9;
string s[103], t[103];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	int rot = 3;
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < (n + 1) / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				int temp = s[i][j];
				s[i][j] = s[j][n - 1 - i];
				s[j][n - 1 - i] = s[n - 1 - i][n - 1 - j];
				s[n - 1 - i][n - 1 - j] = s[n - 1 - j][i];
				s[n - 1 - j][i] = temp;
			}
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cnt += s[i][j] != t[i][j];
			}
		}
		
		ans = min(ans, cnt + rot);
		
		rot--;
	}
	
	printf("%d\n", ans);
	
	return 0;
}