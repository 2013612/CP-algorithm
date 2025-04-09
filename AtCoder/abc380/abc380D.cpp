#include<iostream>
using namespace std;

int q;
string s;

bool rev(long long k) {
	bool r = false;
	long long t = 1;
	
	while (k >= t) {
		t *= 2;
	}
	
	while (k > 0) {
		if (k >= t / 2) {
			r = !r;
			k -= t / 2;
		} else {
			t /= 2;
		}
	}
	
	return r;
}

int main() {
	cin >> s;
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		long long k;
		scanf("%lld", &k);
		k--;
		
		char ans = s[k % s.size()];
		if (rev(k / s.size())) {
			ans = ans ^ 32;
		}
		
		printf("%c ", ans);
	}
	
	return 0;
}