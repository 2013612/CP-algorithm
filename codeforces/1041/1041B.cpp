#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long a, b, x, y, ans;

long long gcd(long long a, long long b) {
	return a == 0? b : gcd(b % a, a);
}

int main(){
	scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
	long long temp = gcd(x, y);
	x /= temp;
	y /= temp;
	ans = min(a/x, b/y);
	printf("%lld\n", ans);
	return 0;
} 
