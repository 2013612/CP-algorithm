#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s, to[10] = {"BC", "CA", "AB"};
long long q;

char find(char c, long long pos, long long t) {
	if (t == 0) {
		return c;
	}
	if (pos < (1ll << (t - 1))) {
		return find(to[c - 'A'][0], pos, t - 1);
	} else {
		return find(to[c - 'A'][1], pos - (1ll << (t - 1)), t - 1);
	}
}

int main() {
	cin >> s >> q;
	while (q-- > 0) {
		long long t, k;
		cin >> t >> k;
		char ans;
		k--;
		if (t >= 60) {
			for (int i = t % 3; i < 63; i += 3) {
				if ((1ll << i) >= k) {
					ans = find(s[0], k, i);
					break;
				}
			}
		} else {
			ans = find(s[k / (1ll << t)], k % (1ll << t), t);
		}
		cout << ans << endl;
	}
	return 0;
}
