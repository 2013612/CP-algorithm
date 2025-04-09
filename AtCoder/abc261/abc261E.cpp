#include<iostream>
using namespace std;

int n, c, ans, b[200006][40][2];
int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < 40; i++) {
		b[0][i][1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int t, a;
		scanf("%d %d", &t, &a);
		if (t == 1) {
			for (int j = 0; j < 30; j++) {
				int p = 0;
				if (a & (1 << j)) {
					p = 1;
				}
				b[i][j][0] = b[i - 1][j][0] & p;
				b[i][j][1] = b[i - 1][j][1] & p;
			}
		} else if (t == 2) {
			for (int j = 0; j < 30; j++) {
				int p = 0;
				if (a & (1 << j)) {
					p = 1;
				}
				b[i][j][0] = b[i - 1][j][0] | p;
				b[i][j][1] = b[i - 1][j][1] | p;
			}
		} else {
			for (int j = 0; j < 30; j++) {
				int p = 0;
				if (a & (1 << j)) {
					p = 1;
				}
				b[i][j][0] = b[i - 1][j][0] ^ p;
				b[i][j][1] = b[i - 1][j][1] ^ p;
			}
		}
		
		
	}
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 0; j < 30; j++) {
			int p = 0;
			if (c & (1 << j)) {
				p = 1;
			}
			temp += b[i][j][p] * (1 << j);
		}
		printf("%d\n", temp);
		c = temp;
	}
	
	return 0;
}