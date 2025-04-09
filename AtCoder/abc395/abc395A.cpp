#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[300005], ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		if (a[i] <= a[i - 1]) {
			ans = 1;
			break;
		}
	}
	
	if (ans) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
	return 0;
}