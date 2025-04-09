#include<iostream>
#include<unordered_map>
using namespace std;

int n, q, a[200006], b[200006];
unordered_map<int, int> um_a[30], um_b[30];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i < n; i++) {
		um_a[0][i] = abs(a[i + 1] - a[i]);
		um_b[0][i] = abs(b[i + 1] - b[i]);
	}
	for (int i = 1; (1 << i) < n; i++) {
		for (int j = 1; j + (1 << i) - 1 < n; j++) {
			um_a[i][j] = gcd(um_a[i - 1][j], um_a[i - 1][j + (1 << (i - 1))]);
			um_b[i][j] = gcd(um_b[i - 1][j], um_b[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i = 0; i < q; i++) {
		int h1, h2, w1, w2;
		scanf("%d %d %d %d", &h1, &h2, &w1, &w2);
		int t1 = 0;
		int t2 = 0;
		while ((1 << t1) <= h2 - h1) {
			t1++;
		}
		while ((1 << t2) <= w2 - w1) {
			t2++;
		}
		t1--;
		t2--;
		int g1 = t1 < 0 ? 0 : gcd(um_a[t1][h1], um_a[t1][h2 - (1 << t1)]);
		int g2 = t2 < 0 ? 0 : gcd(um_b[t2][w1], um_b[t2][w2 - (1 << t2)]);
		printf("%d\n", gcd(a[h1] + b[w1], gcd(g1, g2)));
	}
	return 0;
}