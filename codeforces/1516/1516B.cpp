#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, a[2004];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int x = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			x = (x ^ a[j]);
		}
		if (x == 0) {
			printf("YES\n");
			continue;
		}
		int cou = 0;
		int y = 0;
		for (int j = 0; j < N; j++) {
			y = (y ^ a[j]);
			if (y == x) {
				y = 0;
				cou++;
			}
		}
		if (cou >= 2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
