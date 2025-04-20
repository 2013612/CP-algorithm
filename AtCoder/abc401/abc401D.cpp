#include<bits/stdc++.h>
using namespace std;

int n, k;
string s, t;

int main() {
	scanf("%d %d", &n, &k);
	
	cin >> s;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			k--;
		}
	}
	
	s = "." + s + ".";
	
	for (int i = 1; i <= n; i++) {
		if (s[i] == '?') {
			if (t[i - 2] == 'o' || s[i + 1] == 'o') {
				t.push_back('.');
			} else {
				if (k > 0) {
					t.push_back('?');
				} else {
					t.push_back('.');
				}
			}
		} else {
			t.push_back(s[i]);
		}
	}
	
	if (k > 0) {
		int p = k;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (t[i] == '?') {
				cnt++;
			} else {
				p -= (cnt + 1) / 2;
				cnt = 0;
			}
		}
		
		p -= (cnt + 1) / 2;
		
		if (p == 0) {
			cnt = 0;
			for (int i = 0; i < n; i++) {
				if (t[i] == '?') {
					cnt++;
				} else {
					if (cnt & 1) {
						for (int j = i - cnt; j < i; j++) {
							if ((i - j) & 1) {
								t[j] = 'o';
							} else {
								t[j] = '.';
							}
						}
					}
					cnt = 0;
				}
			}
			
			if (cnt & 1) {
				for (int j = n - cnt; j < n; j++) {
					if ((n - j) & 1) {
						t[j] = 'o';
					} else {
						t[j] = '.';
					}
				}
			}
		}
	}
	
	cout << t << endl;
	return 0;
}