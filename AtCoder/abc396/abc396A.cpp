#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;

int main() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n - 2; i++) {
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
			ans = 1;
		}
	}
	
	if (ans) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}