#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[50], p[1000007];
vector<int> q;

void f(int n) {
	for (int i = 2; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (p[i] == i) {
			q.push_back(i);
		}
		for (auto x : q) {
			if (x > p[i] || x * i > n) {
				break;
			}
			p[x * i] = x;
		}
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	for (auto x : q) {
		if (x == 2) {
			continue;
		}
		if (n % x == 0) {
			printf("%d\n", upper_bound(a, a + 30, n / x) - a);
			return;
		}
	}
}

int main() {
	for (int i = 0; i < 30; i++) {
		a[i] = (1 << (i + 1)) - 1;
	}
	f(1e6);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}