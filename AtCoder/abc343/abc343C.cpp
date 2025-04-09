#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long n;

bool isPar(long long a) {
	string s = to_string(a);
	
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	scanf("%lld", &n);
	
	long long ans = 1;
	for (long long i = 2; i * i * i <= n; i++) {
		if (isPar(i * i * i)) {
			ans = i * i * i;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}