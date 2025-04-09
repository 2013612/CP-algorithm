#include<iostream>
#include<algorithm>
using namespace std;

int N, K, a[100006];

int abs(int a){
	return a >= 0? a : -a;
}

int main(){
	scanf("%d %d", &N, &K);
	int pos = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= 0 && pos < 0) {
			pos = i;
		}
	}
	int ans = 1000000000;
	int c, d;
	if (pos < 0) {
		c = 0;
		d = N - K + 1;
	} else {
		c = max(0, pos - K);
		d = min(N - K + 1, pos + 1);
	}
	for (int i = c; i < d; i++) {
		if (a[i] >= 0) {
			ans = min(ans, a[i + K - 1]);
		} else if (a[i + K - 1] < 0){
			ans = min(ans, abs(a[i]));
		} else {
			ans = min(ans, min(2*abs(a[i]) + a[i + K - 1], abs(a[i]) + 2*a[i + K -1]));
		}
	}
	printf("%d\n", ans);
	return 0;
}
