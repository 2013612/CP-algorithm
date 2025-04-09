#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, ans, a, b;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ans = 0;
		scanf("%lld %lld", &a, &b);
		while (a != 0) {
			if (a % b == 0) {
				a = a/b;
				ans++;
			} else {
				long long temp = a % b;
				a -= temp;
				ans += temp;
			}
			//printf("!%lld\n", a);
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
