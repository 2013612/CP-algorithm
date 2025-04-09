#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, a[100006], b[100006];
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d", &n);
		bool can = true;
		int one = 0;
		int pos = -1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == 1) {
				pos = i;
				one++;
			}
		}
		if (one != 1) {
			printf("NO\n");
			continue;
		} 
		for (int i = 0; i < n; i++) {
			b[i] = a[(i + pos) % n];
		}
		for (int i = 1; i < n; i++) {
			if (i == 1 && b[i] != 2) {
				can = false;
				break;
			}
			if (b[i] > b[i - 1] && b[i] - b[i - 1] > 1) {
				can = false;
				break;
			}
		}
		if (can) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
