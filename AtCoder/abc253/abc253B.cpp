#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int h, w, x[2], y[2], ind;
string s[103];
int main() {
	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == 'o') {
				x[ind] = i;
				y[ind] = j;
				ind++;
			}
		}
	}
	printf("%d\n", abs(x[0] - x[1]) + abs(y[0] - y[1]));
	return 0;
}