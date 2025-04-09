#include<iostream>
#include<vector>
using namespace std;

int pre[100006], q, fac[100006];
vector<int> prime;

void f(int n) {
	for (int i = 0; i <= n; i++) {
		fac[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (fac[i] == i) {
			prime.push_back(i);
		}
		for (auto x:prime) {
			if (i * x > n || x > fac[i]) {
				break;
			}
			fac[i * x] = fac[i];
		}
	}
}

int main() {
	f(100000);
	for (int i = 3; i <= 100000; i++) {
		pre[i] = pre[i - 1];
		if (fac[i] == i && fac[(i + 1) / 2] == (i + 1) / 2) {
			pre[i]++;
		} 
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", pre[r] - pre[l - 1]);
	}
	return 0;
}
