#include<iostream>
using namespace std;

int n, m, a, b, ans;

int cal(int h, int w) {
	h--;
	w--;
	int res = 0;
	
	while (h > 1) {
		res++;
		h /= 2;
	}
	
	while (w > 1) {
		res++;
		w /= 2;
	}
	
	return res + (h > 0) + (w > 0);
}

void solve() {
	scanf("%d %d %d %d", &n, &m, &a, &b);
	ans = min(cal(n - max(a - 1, n - a), m), cal(n, m - max(b - 1, m - b)));
	
	printf("%d\n", ans + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}