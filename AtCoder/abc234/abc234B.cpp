#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int n, a[103], b[103], ans;

int dis(int a, int b) {
	return a * a + b * b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, dis(a[i] - a[j], b[i] - b[j]));
		}
	}
	printf("%.9f\n", sqrt(ans));
	return 0;
}
