#include<iostream>
using namespace std;

int n, k, a[103], ans;

int main() {
	scanf("%d %d", &n, &k);
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		if (k - sum >= a[i]) {
			sum += a[i];
		} else {
			ans++;
			sum = a[i];
		}
	}
	
	printf("%d\n", ans + 1);
	
	return 0;
}