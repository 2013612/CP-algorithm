#include<bits/stdc++.h>
using namespace std;

bool can;
int n, k, a[300005], ans;

void solve() {
	scanf("%d %d", &n, &k);
	ans = 0;
	can = false;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > k) {
			ans++;
		} else {
			ans--;
		}
	}
	
	unordered_map<int, int> fr, bc;
	
	int cnt = 0;
	bc[0] = bc[-1] = -1e9;
	fr[0] = fr[-1] = 1e9;
	
	for (int i = n - 1; i >= 2; i--) {
		if (a[i] > k) {
			cnt++;
		} else {
			cnt--;
		}
		if (cnt <= 0) {
			bc[cnt] = max(bc[cnt], i);
		}
	}
	
	cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		if (a[i] > k) {
			cnt++;
		} else {
			cnt--;
		}
		if (cnt > 0) {
			if (ans - cnt == 0) {
				if (bc[0] > i + 1) {
//					printf("1: %d\n", i);
					can = true;
					break;
				}
			} else if (ans - cnt < 0) {
				if (max(bc[0], bc[-1]) > i + 1) {
//					printf("2: %d\n", i);
					can = true;
					break;
				}
			}
		} else {
			fr[cnt] = min(fr[cnt], i);
		}
	}
	
	if (!can) {
		cnt = 0;
		for (int i = n - 1; i >= 2; i--) {
			if (a[i] > k) {
				cnt++;
			} else {
				cnt--;
			}
			if (cnt > 0) {
//				printf("! %d %d %d %d\n", i, ans, cnt, fr[0]);
				if (ans - cnt == 0) {
					if (fr[0] < i - 1) {
//						printf("3: %d\n", i);
						can = true;
						break;
					}
				} else if (ans - cnt < 0) {
					if (min(fr[0], fr[-1]) < i - 1) {
//						printf("4: %d\n", i);
						can = true;
						break;
					}
				}
			} else {
				int temp = 1e9;
				if (fr.count(0)) {
					temp = fr[0];
				}
				if (fr.count(-1)) {
					temp = min(temp, fr[-1]);
				}
				if (temp < i) {
//					printf("5: %d\n", i);
					can = true;
					break;
				}
			}
		}
	}
	
	if (can) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}