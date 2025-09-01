#include<bits/stdc++.h>
using namespace std;

long long x, y;

int main() {
	scanf("%lld %lld", &x, &y);
	for (int i = 2; i < 10; i++) {
		long long t = x + y;
		string s = to_string(t);
		reverse(s.begin(), s.end());
		t = stoll(s);
		x = y;
		y = t;
	}
	
	printf("%lld\n", y);
	
	return 0;
}