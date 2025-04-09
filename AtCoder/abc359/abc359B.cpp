#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 2 * n - 2; i++) {
		if (a[i] == a[i + 2]) {
			ans++;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}