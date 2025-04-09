#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 1000000007;
int N, Q, a[100006], b[100006];
long long ans;
char x[100006];
int main(){
	scanf("%d %d", &N, &Q);
	scanf("%s", x);
	if (x[0] == '1') {
		a[0] = 1;
	}
	for (int i = 1; i < N; i++) {
		if (x[i] == '1') {
			a[i] = a[i - 1] + 1;
		} else {
			a[i] = a[i - 1];
		}
	}
	b[0] = 1;
	for (int i = 1; i < 100004; i++) {
		b[i] = 2 * b[i - 1] % M;
	}
	for (int i = 0; i < Q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		int temp;
		if (l == 1) {
			temp = a[r - 1];
		} else {
			temp = a[r - 1] - a[l - 2];
		}
		ans = 1ll * (b[temp] - 1) * b[r - l + 1 - temp] % M;
		printf("%lld\n", ans);
	}
	return 0;
}
