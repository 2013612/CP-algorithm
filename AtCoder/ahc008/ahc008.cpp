#include<iostream>
#include<set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, m, map[100][100];
pii h[30];
pipii p[30];
int main() {
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			map[i][j] = 2;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		p[i] = {c, {a, b}};
		map[a][b] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		h[i] = {a, b};
		map[a][b] = 1;
	}
	
	return 0;
}

