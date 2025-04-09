#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[2004], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a[t] = 1;
	}
	for (int i = 0; i <= 2000; i++) {
		if (a[i] == 0) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
