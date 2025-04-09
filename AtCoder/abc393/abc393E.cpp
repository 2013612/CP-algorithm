#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, a[2000006], b[1000006], c[1000006], ans[1000006];

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		b[a[i]]++;
	}
	
	for (int i = 1; i <= 1e6; i++) {
		for (int j = i; j <= 1e6; j += i) {
			c[i] += b[j];
		}
	}
	
	for (int i = 1; i <= 1e6; i++) {
		if (c[i] >= k) {
			for (int j = i; j <= 1e6; j += i) {
				ans[j] = max(ans[j], i);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[a[i]]);
	}
	
	return 0;
}