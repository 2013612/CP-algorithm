#include<iostream>
using namespace std;

int n, t;
bool a[2003][2003];

bool mark(int k) {
	int u = k / n;
	int v = k % n;
	
	a[u][v] = true;
	
	bool can1 = true;
	for (int i = 0; i < n; i++) {
		can1 = can1 && a[u][i];
	}
	bool can2 = true;
	for (int i = 0; i < n; i++) {
		can2 = can2 && a[i][v];
	}
	bool can3 = true;
	for (int i = 0; i < n; i++) {
		can3 = can3 && a[i][i];
	}
	bool can4 = true;
	for (int i = 0; i < n; i++) {
		can4 = can4 && a[n - i - 1][i];
	}
	
	return can1 || can2 || can3 || can4;
}

int main() {
	scanf("%d %d", &n, &t);
	int ans = 1e9;
	for (int i = 0; i < t; i++) {
		int k;
		scanf("%d", &k);
		k--;
		if (mark(k)) {
			ans = min(ans, i + 1);
		}
	}
	
	if (ans > 1e8) {
		ans = -1;
	}
	printf("%d\n", ans);
	
	return 0;
}