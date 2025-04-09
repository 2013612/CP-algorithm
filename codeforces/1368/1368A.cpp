#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long T, N, ans, a, b, A[10005];
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &a, &b, &N);
		A[0] = min(a, b);
		A[1] = max(a, b);
		if (A[1] > N) {
			ans = 1;
		} else {
			for (int j = 2; ; j++) {
				A[j] = A[j - 2] + A[j - 1];
				if (A[j] > N) {
					ans = j - 1;
					break;
				}	
			}
		}

		printf("%lld\n", ans);
	}
	return 0;
}
