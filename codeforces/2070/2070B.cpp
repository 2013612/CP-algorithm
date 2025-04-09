#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x, a[200005];
long long k, ans;

void solve() {
	scanf("%d %d %lld", &n, &x, &k);
	string s;
	cin >> s;
	ans = 0;
	
	if (x != 0) {
		for (int i = 0; i < n && k > 0; i++) {
			if (s[i] == 'L') {
				x--;
			} else {
				x++;
			}
			
			k--;
			
			if (x == 0) {
				ans++;
				break;
			}
		}
	}
	
	if (x == 0) {
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') {
				x--;
			} else {
				x++;
			}
			
			if (x == 0) {
				ans += k / (i + 1);
				break;
			}
		}
	}
	
	
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}
