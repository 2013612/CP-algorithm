#include<iostream>
using namespace std;

int n, m;
long long ans, res;

int main() {
	scanf("%d %d", &n, &m);
	
	res = 1;
	for (int i = 0; i <= m; i++) {
		ans += res;
		res *= n;
		
		if (ans > 1e9) {
			break;
		}
	}
	
	if (ans > 1e9) {
		printf("inf\n");
	} else {
		printf("%lld\n", ans);
	}
	
	return 0;
}