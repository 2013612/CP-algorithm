#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long N, A, B, K, a[200006], ans;

int main() {
	scanf("%d %d %d %d", &N, &A, &B, &K);
	for (int i = 0; i < N; i++) {
		long long temp;
		scanf("%I64d", &temp);
		temp = temp % (A + B);
		if (temp == 0) {
			temp = A + B;
		}
		a[i] = temp / A;
		if (temp % A == 0) {
			a[i]--;
		}
	}
	sort(a, a + N);
	for (int i = 0; i < N; i++) {
		if (a[i] <= K) {
			ans++;
			K -= a[i];
		} else {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
