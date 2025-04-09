#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, q;
long long x, y;
int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%lld %lld", &x, &y);
		if ((x + y) % 2 == 0) {
			if (y % 2 == 0) {
				printf("%lld\n", (x - 1)/2*1ll*n + 1ll*(n + 1)/2 + y/2);
			} else {
				printf("%lld\n", (x - 1)/2*1ll*n + (y + 1)/2);
			}
		} else {
			if (y % 2 == 0) {
				printf("%lld\n", (1ll*n*n + 1)/2 + (x - 1)/2*1ll*n + y/2);
			} else {
				printf("%lld\n", (1ll*n*n + 1)/2 + (x - 1)/2*1ll*n + 1ll*n/2 + (y + 1)/2);
			}
		}
	}
	return 0;
}
