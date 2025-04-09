#include<iostream>
using namespace std;

int n, a[1000006], sum[1000006];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		sum[l]++;
		sum[r + 1]--;
	}
	for (int i = 1; i <= 1000000; i++) {
		sum[i] += sum[i - 1];
	}
	int maxi = 0;
	for (int i = 0; i <= 1000000; i++) {
		maxi = max(maxi, sum[i]);
	}
	printf("%d\n", maxi);
	return 0;
}
