#include<iostream>
using namespace std;

int n, a[103];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int ans = -1;
	
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[0]) {
			ans = i + 1;
			break;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}