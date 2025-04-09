#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		int maxi = min(N/K, M);
		if (maxi == 0 || M >= N - K + 2) {
			ans = 0;
		} else {
			M -= maxi;
			ans = maxi - M/(K - 1);
			if (M % (K - 1) != 0) {
				ans--;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
