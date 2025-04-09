#include<bits/stdc++.h>
using namespace std;

int n, ans, a[300005];
bool x, y;

int main() {
	n = 7;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		a[k]++;
	}
	
	for (int i = 1; i <= 13; i++) {
		if (a[i] >= 3) {
			if (x) {
				y = true;
			} else {
				x = true;
			}
		} else if (a[i] >= 2) {
			y = true;
		}
	}
	
	if (x && y) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}