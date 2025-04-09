#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, a[100006], ans, maxi, sum;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		maxi = max(maxi, a[i]);
		sum += a[i];
	}
	if ((sum + M) % N == 0) {
		ans = (sum + M) / N;
	} else {
		ans = (sum + M) / N + 1;
	}
	ans = max(ans, maxi);
	printf("%d %d\n", ans, maxi + M);
	return 0;
}
