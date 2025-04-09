#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, ans, a[100006], b[100006], cou[100006];
int main() {
	scanf("%lld", &N);
	for (int j = 0; j < N; j++) {
		scanf("%lld", &a[j]);
	}
	for (int j = 1; j <= N; j++) {
		scanf("%lld", &b[j]);
	}
	for (int j = 0; j < N; j++) {
		long long temp;
		scanf("%lld", &temp);
		cou[b[temp]]++;
	}
	for (int j = 0; j < N; j++) {
		ans += cou[a[j]];
	}
	printf("%lld\n", ans); 
	return 0;
}
