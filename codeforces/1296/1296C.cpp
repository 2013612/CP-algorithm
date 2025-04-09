#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int T, N, ans;
pair<int, int> a[300006];

int main() {
	scanf("%d", &T);
	pair<int, int> Z = make_pair(0, 0);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		string s;
		ans = 0;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'L') {
				a[j] = make_pair(-1, 0);
			} else if (s[j] == 'R') {
				a[j] = make_pair(1, 0);
			} else if (s[j] == 'U') {
				a[j] = make_pair(0, 1);
			} else {
				a[j] = make_pair(0, -1);
			}
		}
		int count = 1;
		while (count <= N) {
			bool done = false;
			for (int j = 0; j < N - (count - 1); j++) {
				if (a[j] == Z) {
					done = true;
					ans = j + 1;
					break;
				} else if (j + 2 * count <= N) {
					a[j] = make_pair(a[j].first + a[j + count].first, a[j].second + a[j + count].second);
					//cout << "!" << j << " " << a[j].first << " " << a[j].second << endl;
				}
			}
			if (done) {
				break;
			}
			count *= 2;
		}
		if (ans == 0) {
			cout << -1 << endl;
		} else {
			cout << ans << " " << ans + count - 1 << endl;
		}
	}
	return 0;
}
