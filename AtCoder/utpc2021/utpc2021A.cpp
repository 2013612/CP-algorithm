#include<iostream>
#include<vector>
using namespace std;

int n, ans = 1e9;
string s, S = "UTPC";
int main() {
	cin >> n >> s;
	for (int i = 0; i < n - 3; i++) {
		string st = s.substr(i, 4);
		int cur_ans = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = j + 1; k < 4; k++) {
				if (st[j] == S[k] && st[k] == S[j]) {
					swap(st[j], st[k]);
					cur_ans++;
					break;
				}
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					if (j == k || k == l || j == l) {
						continue;
					}
					if (st[j] == S[k] && st[k] == S[l] && st[l] == S[j]) {
						swap(st[j], st[k]);
						swap(st[j], st[l]);
						cur_ans += 2;
						break;
					}
				}
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					for (int m = 0; m < 4; m++) {
						if (j == k || k == l || j == l || l == m || j == m || k == m) {
							continue;
						}
						if (st[j] == S[k] && st[k] == S[l] && st[l] == S[m] && st[m] == S[j]) {
							cur_ans += 3;
							st = S;
							break;
						}
					}
				}
			}
		}
		for (int j = 0; j < 4; j++) {
			if (st[j] != S[j]) {
				cur_ans++;
			}
		}
		ans = min(ans, cur_ans);
	}
	printf("%d\n", ans);
	return 0;
}
