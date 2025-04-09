#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n;
long long d, b, c[150006];
vector<bool> a;

long long gcd(long long a,long long b){
	return a == 0? b : gcd(b%a,a);
}

long long lcm(long long a,long long b){
	return (1ll*a/gcd(a,b)*b);
}

void outputprime(long long n){
	a.push_back(false);
	a.push_back(false);
	for(int i = 2; i <= n; i++){
		a.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (a[i] == false){
			continue;
		} else{
			for (int j = 2*i; j <= n; j+=i){
				a[j] = false;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	long long ans = 0;
	long long maxi = 20000000001;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &d, &b);
		if (n == 1) {
			ans = max(d, b);
		}
		maxi = min(max(b, d), maxi);
		c[i] = lcm(d, b);
	}
	for (int i = 0; i < n; i++) {
		if (n == 1) break;
		ans = gcd(ans, c[i]);
	}
	outputprime(maxi);
	for (int i = 2; i <= maxi; i++) {
		if (a[i] && ans % i == 0) {
			ans = i;
			break;
		}
	}
	if (ans == 1) {
		printf("-1\n");
	} else {
		printf("%lld\n", ans);
	}
	return 0;
}
