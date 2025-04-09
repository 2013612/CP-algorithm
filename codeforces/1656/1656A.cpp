#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		int ans1, ans2;
		int mini = 2e9;
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			if (t > maxi) {
				maxi = t;
				ans1 = i + 1;
			}
			if (t < mini) {
				mini = t;
				ans2 = i + 1;
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
