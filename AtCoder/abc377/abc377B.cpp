#include<iostream>
#include<algorithm>
using namespace std;

int ans = 0;

int main() {
	string s[10];
	s[0] = s[9] = "!!!!!!!!!!!!!!!";
	for (int i = 1; i <= 8; i++) {
		cin >> s[i];
		s[i] = "!" + s[i] + "!";
	}
	
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (s[i][j] == '#') {
				for (int u = 1; u <= 8; u++) {
					if (s[u][j] != '#') {
						s[u][j] = '!';
					}
					if (s[i][u] != '#') {
						s[i][u] = '!';
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (s[i][j] == '.') {
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}