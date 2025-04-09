#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, T, ans;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		ans = 0;
		while (N >= 10) {
			long long temp = N / 10;
			//cout << "!" << temp << endl;
			ans += temp * 10;
			N -= temp * 9;
		}
		ans += N;
		printf("%lld\n", ans);
	}
	
	return 0;
}
