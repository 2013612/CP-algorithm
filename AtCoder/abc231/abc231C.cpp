#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, q, ans, a[200006];
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		int ind = lower_bound(a, a + n, t) - a;
		printf("%d\n", n - ind);
	}
	return 0;
}
