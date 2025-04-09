#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

long long N, ans, a;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ans = 0;
		scanf("%lld", &a);
		while (a != 1) {
			if (a % 2 == 0) {
				a /= 2;
				ans++;
			} else if (a % 3 == 0) {
				a /= 3;
				ans += 2;
			} else if (a % 5 == 0) {
				a /= 5;
				ans += 3;
			} else {
				break;
			}
		}
		if (a == 1) {
			printf("%d\n", ans);
		} else {
			printf("-1\n");
		}
	}
	
	return 0;
}
