#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, M, ans;
long long a[300006], b[300006], sum1, sum2;
int main(){
	scanf("%d", &N);
	for (int i = 0 ; i < N; i++) {
		scanf("%d", &a[i]);
		sum1 += a[i];
	}
	scanf("%d", &M);
	for (int i = 0 ; i< M; i++) {
		scanf("%d", &b[i]);
		sum2 += b[i];
	}
	if (sum1 != sum2) {
		printf("-1\n");
		return 0;
	}
	int l1, r1;
	int l2, r2;
	l1 = l2 = 0;
	r1 = r2 = 1;
	while(l1 < N) {
		if (a[l1] == b[l2]) {
			l1 = r1;
			l2 = r2;
			r1++;
			r2++;
			ans++;
		} else if (a[l1] < b[l2]) {
			a[l1] += a[r1];
			r1++;
		} else {
			b[l2] += b[r2];
			r2++;
		}
	}
	printf("%d", ans);
	return 0;
}
