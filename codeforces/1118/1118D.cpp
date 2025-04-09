#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long N, a[200006], M, SUM;

bool f(int x, int y) {
	return x > y;
}

int main(){
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		SUM += a[i];
	}
	sort(a, a + N, f);
	if (SUM < M) {
		printf("-1\n");
		return 0;
	} else {
		long long l = 1;
		long long r = N;
		while (l < r) {
			long long mid = (l + r)/2;
			//long long minus = (N/mid - 1) * (N/mid) / 2 * mid + (N % mid) * (N/mid);
			long long temp_sum = 0;
			bool can = false;
			for (int i = 0; i < N; i++) {
				temp_sum += max(1ll*0, a[i] - i/mid);
				if (temp_sum >= M) {
					can = true;
					break;
				}
			}
			if (can) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		printf("%lld\n", l);
	}
	return 0;
}
