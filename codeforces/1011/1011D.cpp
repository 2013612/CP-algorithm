#include<iostream>
using namespace std;

int m, n, a[31];
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n ; i++){
		printf("%d\n", m);
		fflush(stdout);
		scanf("%d", &a[i]);
		if (a[i] == 0){
			return 0;
		}
	}
	int l = 1;
	int r = m;
	int i = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		printf("%d\n", mid);
		fflush(stdout);
		int k;
		scanf("%d", &k);
		if (k*a[i] == 1) {
			r = mid - 1;
		} else if (k*a[i] == -1) {
			l = mid + 1;
		} else {
			return 0;
		}
		if (i == n - 1) {
			i = 0;
		} else {
			i++;
		}
	}
}
