#include<iostream>
#include<algorithm>
using namespace std;

int t, a[100006], b[100006];

int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			a[i] = 0;
			b[i] = i;
		}
		random_shuffle(b + 1, b + n + 1);
		int r, p;
		cin >> r >> p;
		a[r] = p;
		int cnt = 0;
		for (int i = 1; cnt < min(n, k); i++) {
			if (a[b[i]] == 0) {
				cout << "T " << b[i] << endl;
				cin >> r >> p;
				a[r] = p;
				cnt++;
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += a[i];
		}
		ans *= n;
		ans /= min(n, k);
		ans /= 2;
		cout << "E " << ans << endl;
	}
	return 0;
}
