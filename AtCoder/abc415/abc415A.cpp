#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans, x;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &x);
	
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			printf("Yes\n");
			return 0;
		}
	}
	
	printf("No\n");
	
	return 0;
}