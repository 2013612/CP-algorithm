#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, N, M, K, a[10005], b[10005], ans;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N, &M, &K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			b[N - 1 - j] = a[j];
		}
		int temp = M - K - 1;
		int maxi = 0;
		int maxi2 = 0;
		for (int j = M; j >= temp - 1; j--) {
			maxi = max(maxi, max(a[j + 1], a[N - 1 + j - M]));
		}
		for (int j = M; j >= temp - 1; j--) {
			maxi2 = max(maxi, max(b[j + 1], b[N - 1 + j - M]));
		}
		printf("%d\n", min(maxi, maxi2));
	}
	
	return 0;
}
