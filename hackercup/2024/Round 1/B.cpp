#include<iostream>
#include<vector>
using namespace std;

int a[10000007];

vector<bool> v(10000007);

void seive() {
	int N = 10000005;
	for (int i = 0; i < N; i++) {
		v[i] = true;
	}
	v[0] = v[1] = false;
	
	for (int i = 2; i * i < N; i++) {
		if (v[i]) {
			for (int j = 2 * i; j < N; j += i) {
				v[j] = false;
			}
		}
	}
	
	a[5] = 2;
	
	for (int i = 6; i < N; i++) {
		a[i] = a[i - 1];
		if (v[i] && v[i - 2]) {
			a[i]++;
		}
	}
}

void solve() {
	int n;
	scanf("%d", &n);

	printf("%d\n", a[n]);
}

int main() {
	freopen("prime_subtractorization_input.txt", "r", stdin);
	freopen("prime_subtractorization_output.txt", "w", stdout);
	seive();
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}