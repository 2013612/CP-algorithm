#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1e9 + 7;

long long n, a, b;

vector<bool> v;
vector<long long> prime;

void f(int n) {
	// printf("^ %d\n", n);
	v.push_back(false);
	v.push_back(false);
	for(int i = 2; i <= n; i++){
		v.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (v[i] == false){
			continue;
		} else {
			for (int j = 2*i; j <= n; j+=i){
				v[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (v[i]) {
			prime.push_back(i);
		}
	}

	// if (v[5000011]) {
	// 	printf("Yes\n");
	// } else {
	// 	printf("No\n");
	// }
}

long long pow(long long a, long long x) {
	if (x == 0) {
		return 1;
	}

	if (x & 1) {
		return a * pow(a, x - 1) % M;
	} else {
		long long temp = pow(a, x / 2);
		return temp * temp % M;
	}
}

long long inv(long long a) {
	return pow(a, M - 2);
}

long long nhr(long long n, long long r) {
	long long res = 1;
	for (long long i = n + r - 1; i >= n; i--) {
		res = (res * (i % M)) % M;
	}

	for (long long i = 2; i <= r; i++) {
		res = (res * inv(i)) % M;
	}

	return res % M;
}

long long g(long long x) {
	vector<int> p;

	long long temp = x;

	for (auto y: prime) {
		// printf("$ %d\n", y);
		if (temp % y == 0) {
			// printf("^ %d\n", y);
			p.push_back(0);

			while (temp % y == 0) {
				p.back()++;
				temp /= y;
			}
		}

		if (temp < y) {
			break;
		}
	}

	if (temp > 1) {
		p.push_back(1);
	}

	// printf("## %lld\n", x);
	// for (auto y : p) {
	// 	printf("%lld ", y);
	// }
	// printf("\n");

	long long res = 1;
	for (auto y: p) {
		res = res * nhr(n, y);
		res %= M;

		// printf("@ %lld %lld %lld\n", res, y, ncr(n, y));
	}

	return res;
}

void solve() {
	scanf("%lld %lld %lld", &n, &a, &b);
	long long ans = 0;

	vector<long long> q;

	for (long long i = 1; i * i <= b; i++) {
		if (b % i == 0) {
			q.push_back(i);

			if (i != b / i) {
				q.push_back(b / i);
			}
		}
	}

	// for (auto x: q) {
	// 	printf("%lld \n", x);
	// }

	// printf("\n");

	sort(q.begin(), q.end());

	for (auto x: q) {
		if (x > a) {
			break;
		}

		long long u = g(x);
		long long v = g(b / x);

		ans += u * v % M;
		ans %= M;

		// printf("!! %lld %lld %lld\n", x, u, v);
	}

	printf("%lld\n", ans);
}

int main() {
	freopen("final_product_chapter_2_input.txt", "r", stdin);
	freopen("final_product_chapter_2_output.txt", "w", stdout);

	f(1e7 + 10);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}