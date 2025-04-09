#include<bits/stdc++.h>
using namespace std;

int n;
long long l, r;

void solve() {
	scanf("%d", &n);
	l = r = 1;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		pair<char, long long> op[2];
		cin >> op[0].first >> op[0].second >> op[1].first >> op[1].second;
//		scanf("%c %d %c %d", &op[0].first, &op[0].second, &op[1].first, &op[1].second);
//		printf("%c %d %c %d\n", op[0].first, op[0].second, op[1].first, op[1].second);
		
		if (op[0].first == op[1].first) {
			if (op[0].first == '+') {
				cnt += op[0].second + op[1].second;
			} else {
				if (op[0].second == op[1].second) {
					cnt *= op[0].second;
					cnt += (l + r) * (op[0].second - 1);
				} else {
					long long k = cnt;
					if (op[0].second == 2) {
						r += k;
						cnt = 2 * r + l;
					} else {
						l += k;
						cnt = 2 * l + r;
					}
				}
			}
		} else {
			long long k = cnt;
			if (op[0].first == '+') {
				r += k;
				cnt = op[0].second + (op[1].second - 1) * r;
			} else {
				l += k;
				cnt = op[1].second + (op[0].second - 1) * l;
			}
		}
//		printf("%lld %lld %lld\n", l, r, cnt);
	}
	
	printf("%lld\n", l + r + cnt);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
}