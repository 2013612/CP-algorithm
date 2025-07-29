#include<iostream>
using namespace std;

int m, n, a[103], b[103], ans;

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	
	for (int i = 1; i <= m; i++) {
		if (b[i] == 0) {
			printf("0\n");
			return 0;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		b[a[i]]--;
		ans++;
		
		if (a[i] <= m && b[a[i]] == 0) {
			break;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}