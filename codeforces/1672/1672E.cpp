#include<iostream>
using namespace std;

int n, ans;
int main() {
	scanf("%d", &n);
	int l = 1, r = 2000 * 2001;
	while (l < r) {
		int mid = (l + r) / 2;
		cout << "? " << mid << endl;
		int t;
		cin >> t;
		if (t != 1) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	ans = l;
	for (int i = 2; i <= n; i++) {
		int w = l / i;
		cout << "? " << w << endl;
		int t;
		cin >> t;
		if (t == 0) {
			break;
		}
		ans = min(ans, t * w);
	}
	cout << "! " << ans << endl;
	return 0;
}
