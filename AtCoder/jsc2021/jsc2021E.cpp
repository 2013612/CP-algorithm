#include<iostream>
#include<string>
using namespace std;

int K;
string S;
bool change[500006];

bool check_pali(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int find_level(int left, int length) {
	if (length == 0 || !check_pali(S.substr(left, length))) {
		return 0;
	} else {
		return find_level(left, length / 2) + 1;
	}
}

bool to_pali(string s, int level, int left, int length) {
	if (level == 1 && (length == 2 || length == 3)) {
		return false;
	}
	if (level == 0) {
		if (length == 0 || !check_pali(s.substr(left, length))) {
			return true;
		} else {
			if (S[left] != 'p') {
				S[left] = 'p';
			} else {
				S[left] = 't';
			}
			change[left] = true;
			return true;
		}
	}
	bool can = to_pali(s, level - 1, left, length / 2);
	int right = left + (length + 1) / 2;
	for (int i = 0; i < length / 2; i++) {
		if (S[right + i] != S[left + i]) {
			if (!change[left + i] && !change[right + i]) {
				S[right + i] = S[left + i];
				change[right + i] = true;
			} else {
				if (change[left + i]) {
					S[left + i] = S[right + i];
				} else {
					S[right + i] = S[left + i];
				}
			}
		}
	}
	return can;
}

int main() {
	cin >> K >> S;
	if ((1 << (K - 1)) > S.length() || !to_pali(S, K, 0, S.length())) {
		printf("impossible\n");
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < S.length(); i++) {
		if (change[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
