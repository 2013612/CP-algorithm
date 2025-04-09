#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long N, M, two, ans;
const int K = 998244353;

long long fac(long long x) {
	long long temp = 1;
	for (int i = 1; i <= x; i++) {
		temp = (temp * i) % K;
	}
	return temp;
}

long long power(long long x, long long y, long long m) { 
    if (y == 0) 
        return 1; 
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

long long modInverse(long long a, long long m) { 
    return power(a, m-2, m); 
}

int main(){
	scanf("%lld %lld", &N, &M);
	two = 1;
	for (int i = 0; i < N - 3; i++) {
		two = two*2 % K;
	}
	ans = two * (N - 2) % K;
	//cout << ans << endl;
	ans = ans * fac(M) % K;
	//cout << ans << endl;
	ans = ans * modInverse(fac(N - 1), K) % K;
	//cout << modInverse(2, K) << endl;
	ans = ans * modInverse(fac(M - (N - 1)), K) % K;
	printf("%lld\n", ans);
	return 0;
}
