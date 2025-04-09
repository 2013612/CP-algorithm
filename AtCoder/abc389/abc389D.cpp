#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long r, ans;

int main() {
	scanf("%lld", &r);
	
	r *= 2;
	
	long long j = 2;
	
	while (1 + (j + 1) * (j + 1) <= r * r) {
		j += 2;
		ans++;
	}
	
	for (long long i = 2; j > 0; i += 2) {
		while (j > 0 && (i + 1) * (i + 1) + (j + 1) * (j + 1) > r * r) {
			j -= 2;
		}
		
		ans += j / 2;
	}
	
	ans *= 4;
	
	printf("%lld\n", ans + 1);
	
	return 0;
}