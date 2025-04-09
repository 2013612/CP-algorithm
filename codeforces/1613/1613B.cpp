#include<iostream>
#include<algorithm>
using namespace std;

int t, n, a[200006];
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n / 2; i++) {
			printf("%d %d\n", a[i + 1], a[0]);
		}
	}
	return 0;
}
