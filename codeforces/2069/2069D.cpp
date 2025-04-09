#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200005], ans, ind;

int f(string s) {
	int l = 0, r = n - 2 * ind;
	
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		
		bool can = false;
		
		int cnt[26];
		for (int i = 0; i < 26; i++) {
			cnt[i] = 0;
		}
		for (int i = ind; i < ind + mid; i++) {
			cnt[s[i] - 'a']++;
		}
		
		if (ind + mid > n / 2) {
			int temp = ind + mid - n / 2;
			int end = n / 2 - temp;
			for (int i = ind; i < end; i++) {
				if (cnt[s[n - i - 1] - 'a']) {
					cnt[s[n - i - 1] - 'a']--;
				} else {
					break;
				}
				
				if (i == end - 1) {
					can = true;
				}
			}
		} else {
			for (int i = ind; i < ind + mid; i++) {
				if (cnt[s[n - i - 1] - 'a']) {
					cnt[s[n - i - 1] - 'a']--;
				} else {
					break;
				}
				
				if (i == ind + mid - 1) {
					can = true;
				}
			}
			
			for (int i = ind + mid; i < n / 2; i++) {
				if (s[i] != s[n - i - 1]) {
					can = false;
				}
			}
		}
		
		if (can) {
			r = mid;
		} else {
			l = mid;
		}
	}
	
	return r;
}

void solve() {
	string s;
	cin >> s;
	n = s.length();
	
	ind = -1;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			ind = i;
			break;
		}
	}
	
	if (ind == -1) {
		printf("0\n");
		return;
	}
	
	string t = s;
	reverse(t.begin(), t.end());
	ans = min(f(s), f(t));
	
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}