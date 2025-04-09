#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
using namespace std;

long long x, m, ans;

//void brute() {
//	long long temp = 0;
//	for (int i = 1; i <= m; i++) {
//		int a = x ^ i;
//		if (a % i == 0 || a % x == 0) {
//			temp++;
//		}
//	}
//	
//	if (ans != temp) {
//		printf("ERROR!!!\n");
//		printf("Case: %lld %lld\n", x, m);
//		printf("%lld %lld\n", ans, temp);
//	}
//}

//string f(long long value)
//{
//    string str(10, '0');
//
//    for(int i = 0; i < 10; i++)
//    {
//        if( (1ll << i) & value)
//            str[9-i] = '1';
//    }
//
//    return str;
// }

void solve() {
	scanf("%lld %lld", &x, &m);
//	x = rand() % 100 + 1;
//	m = rand() % 1000 + 1;
//	x = 1;
//	m = 6;
	
	ans = 0;
	
	if (x >= m) {
		for (int i = 1; i <= m; i++) {
			int a = x ^ i;
			if (a % i == 0 || a % x == 0) {
				ans++;
			}
		}
		
		printf("%lld\n", ans);
		
		return;
	}
	
	long long k = 1;
	
	while (k - 1 < m) {
		k *= 2;
	}
	
	k--;
	
	ans = k / x;
	
	long long cur = m + 1;
	long long next = m;
	
	int p = x;
	
	while (cur <= k) {
		next = cur;
		for (long long i = 0; i < 64; i++) {
			long long a = 1ll << i;
			if (next & a) {
				break;
			}
			if (p & a) {
				p -= a;
			}
			next += a;
		}
		
//		printf("!!! %lld\n", ans);
//		printf("next, cur: %lld %lld %lld %lld \n", next, cur, next ^ p, cur ^ p);
//		printf("next, cur: %s %s %s %s \n", f(next).c_str(), f(cur).c_str(), f(next ^ p).c_str(), f(cur ^ p).c_str());
		
		ans -= abs(((next ^ p) / x) - (((cur ^ p) - 1) / x));
		cur = next + 1;
	}
	
//	printf("!! %lld\n", ans);
	
	for (int i = 1; i <= min<long long>(x, m); i++) {
		int a = x ^ i;
		if (a % i == 0 && a % x != 0) {
			ans++;
		}
	}
	
//	if (m % x == 0) {
//		ans--;
//	}
	
	printf("%lld\n", ans);
	
//	brute();
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}