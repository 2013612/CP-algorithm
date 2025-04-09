#include<iostream>
using namespace std;

int n, a[103];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n - 2; i++) {
		if (1ll * a[i] * a[i + 2] != 1ll * a[i + 1] * a[i + 1]) {
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
	
	return 0;
}