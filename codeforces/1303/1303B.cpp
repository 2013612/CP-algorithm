#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long T, N, G, B, ans;
int main() {
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld %lld", &N, &G, &B);
		long long temp = N/2;
		if (N % 2 == 1) {
			temp++;
		}
		long long count = temp/G;
		if (temp % G == 0) {
			count--;
		}
		long long less = N - G * count - min(N - temp, B * count);
		//cout << count << " " << temp << " " << less << endl;
		ans = (G + B) * count + less;
		printf("%lld\n", ans);
	}
	return 0;
}
