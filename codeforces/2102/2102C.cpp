#include<bits/stdc++.h>
using namespace std;

int y[4] = {1, 0, -1, 0};
int x[4] = {0, 1, 0, -1};

int n, a[503][503];
long long ans;

bool check(int i, int j) {
	bool is_i_in = i >= 0 && i < n;
	bool is_j_in = j >= 0 && j < n;
	return is_i_in && is_j_in && a[i][j] == -1;
}

void solve() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = -1;
		}
	}
	
	int cur = 0;
	int u = 0;
	int v = -1;
	
	for (int i = n * n - 1; i >= 0; i--) {
		while (!check(u + x[cur], v + y[cur])) {
			cur++;
			cur %= 4;
		}
		
		u = u + x[cur];
		v = v + y[cur];
		
		a[u][v] = i;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}