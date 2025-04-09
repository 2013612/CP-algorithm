#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, a[1004], ans, sum;

int abs (int x) {
	return x > 0? x : -x;
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < K; i++) {
		int temp = 0;
		for (int j = i; j < N; j += K) {
			temp += a[j];
		}
		ans = max(ans, abs(sum - temp));
	}
	printf("%d\n", ans);
	return 0;
}
