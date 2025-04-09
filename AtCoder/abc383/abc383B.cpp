#include<iostream>
using namespace std;

int h, w, d, ans;
string s[20];
bool a[20][20];

void cnt(int x1, int y1, int x2, int y2) {
	int c = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.' && (abs(i - x1) + abs(j - y1) <= d || abs(i - x2) + abs(j - y2) <= d)) {
				a[i][j] = true;
				c++;
			}
		}
	}
	
	ans = max(ans, c);
}

int main() {
	scanf("%d %d %d", &h, &w, &d);
	
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < h; k++) {
				for (int l = 0; l < w; l++) {
					if (s[i][j] == '.' && s[k][l] == '.') {
						cnt(i, j, k, l);
					}
				}
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}