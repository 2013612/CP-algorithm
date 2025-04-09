#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long N, K, ans;
int main(){
	scanf("%lld %lld", &N, &K);
	ans = K/N;
	if (K % N != 0) {
		ans += 1;
	}
	printf("%lld\n", ans);
	return 0;
}
