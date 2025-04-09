#include<iostream>
#include<unordered_set>
using namespace std;

string s, t;
int N;
unordered_set<string> us;

bool find(string ans, string left) {
	if (ans.length() == s.length()) {
		cout << ans << endl;
		return true;
	}
	if (us.count(left)) {
		return false;
	}
	bool can = false;
	for (int i = 0; i < 26; i++) {
		if (left[i] != '0' && s[ans.length()] - 'a' != i) {
			left[i] = char(left[i] - 1);
			can = can || find(ans + char('a' + i), left);
			left[i] = char(left[i] + 1);
		}
		if (can) {
			return true;
		}
	}
	us.insert(left);
	return false;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        cin >> s;
        t = "";
        us.clear();
        int occ[26];
        for (int j = 0; j < 26; j++) {
        	occ[j] = 0;
		}
        for (int j = 0; j < s.length(); j++) {
        	occ[s[j] - 'a']++;
		}
        for (int j = 0; j < 26; j++) {
        	t.push_back(char(occ[j] + '0'));
		}
		printf("Case #%d: ", i);
		if (!find("", t)) {
			cout << "IMPOSSIBLE" << endl;
		}
    }
}
