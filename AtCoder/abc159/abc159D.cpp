#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, a[300006], b[300006], ans;
int main(){
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		b[a[i]]++;
	}
	for (int i = 0; i <= N; i++) {
		ans += b[i]*(b[i] - 1)/2;
	}
	for (int i = 0; i < N; i++) {
		printf("%lld\n", ans - b[a[i]] + 1);
	}
	return 0;
}
