#include<iostream>
#include<unordered_set>
using namespace std;

int n, l, x[103][10], ans = 1e9;
int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			scanf("%d", &x[i][j]);
		}
	}
	for (int k = 1; k < (1 << l); k++) {
		unordered_set<int> us;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < l; j++) {
				if (k & (1 << j)) {
					sum += x[i][j] * (1 << j);
				}
			}
			us.insert(sum);
		}
		if (us.size() == n) {
			int cnt = 0;
			int cur = k;
			while (cur != 0) {
				if (cur & 1) {
					cnt++;
				}
				cur >>= 1;
			}
			ans = min(ans, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}