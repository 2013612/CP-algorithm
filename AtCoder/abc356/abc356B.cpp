#include<iostream>
using namespace std;

int n, m, a[103];

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			a[j] -= x;
		}
	}
	
	bool ans = true;
	for (int i = 0; i < m; i++) {
		ans = ans && (a[i] <= 0);
	}
	
	if (ans) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}