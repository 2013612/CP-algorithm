#include<iostream>
#include<algorithm>
using namespace std;

int n, a[200006][3];
string s;

int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		int t = 0;
		if (s[i] == 'P') {
			t = 1;
		} else if (s[i] == 'S') {
			t = 2;
		}
		
		for (int j = 0; j < 3; j++) {
			if (j == (t + 2) % 3) {
				continue;
			}
			
			a[i + 1][j] = max(a[i][(j + 1) % 3], a[i][(j + 2) % 3]) + (j == (t + 1) % 3);
		}
	}
	
	printf("%d\n", max({a[n][0], a[n][1], a[n][2]}));
	
	return 0;
}