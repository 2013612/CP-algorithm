#include<iostream>
using namespace std;

int n, l[200006], r[200006], ans[200006];
long long sum;

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		sum += l[i];
		ans[i] = l[i];
	}
	
	for (int i = 0; i < n; i++) {
		ans[i] = min(1ll * r[i], l[i] + abs(sum));
		sum += ans[i] - l[i];
	}
	
	if (sum != 0) {
		printf("No\n");
	} else {
		printf("Yes\n");
		for (int i = 0; i < n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}