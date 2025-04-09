#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, Q, X[100006], L;
int main(){
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &L);
		int l = 0;
		int r = L;
		int ans = 0;
		for (int j = 0; j < N; j++) {
			if (X[j] > r) {
				ans += X[j] - r;
				r = X[j];
				l = X[j] - L;
			} else if (X[j] < l) {
				ans += l - X[j];
				l = X[j];
				r = X[j] + L;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
