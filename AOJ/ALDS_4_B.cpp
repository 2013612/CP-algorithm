#include<iostream>
using namespace std;

int N, Q, S[100005], ans;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &S[i]);
	}
	S[0] = -1;
	S[N + 1] = 2e9;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);
		int left = 0;
		int right = N + 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (q <= S[mid]) {
				right = mid;
			} else {
				left = mid + 1; 
			}
		}
		if (S[left] == q) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
