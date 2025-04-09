#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

long long N, ans, a[2000007];
set<int> s;
int main() {
	scanf("%lld", &N);
	for (int i = 0; i < (1 << 20); i++) {
		s.insert(i);
		a[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		long long t, x;
		scanf("%lld %lld", &t, &x);
		if (t == 1) {
			int h = x % (1 << 20);
			auto temp = s.lower_bound(h);
			if (temp == s.end()) {
				temp = s.lower_bound(0);
			}
			a[*temp] = x;
			s.erase(temp);
		} else {
			printf("%lld\n", a[(x % (1 << 20))]);
		}
	}
	return 0;
}
