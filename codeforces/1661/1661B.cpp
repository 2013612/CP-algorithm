#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

const int M = 32768;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int ans = 15;
		for (int j = 0; j < 15; j++) {
			int t = 15 + j;
			int p = (a + j) % M;
			if (p == 0) {
				ans = j;
				break;
			}
			while (p % 2 == 0) {
				t--;
				p >>= 1;
			}
			ans = min(ans, t);
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}
