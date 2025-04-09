#include<iostream>
#include<stack>
using namespace std;

string s, ans, ans2;
int pos[500006];
stack<int> st;

char rev(char a) {
	if (a >= 'a' && a <= 'z') {
		return 'A' + (a - 'a');
	} else {
		return 'a' + (a - 'A');
	}
}

void solve(int p1, int p2, int k1, int k2, int cnt) {
	for (int i = p1 + 1; i < p2; i++) {
		if (s[i] != '(') {
			if (cnt & 1) {
				ans[k2 - (i - (p1 + 1))] = rev(s[i]);
			} else {
				ans[k1 + i - (p1 + 1)] = s[i];
			}
		} else {
			int x1, x2;
			if (cnt & 1) {
				x1 = k2 - (i - p1) - (pos[i] - i - 1);
				x2 = k2 - (i - p1);
			} else {
				x1 = k1 + (i - (p1 + 1));
				x2 = k1 + (i - (p1 + 1)) + (pos[i] - (i + 1));
			}
			solve(i, pos[i], x1, x2, cnt + 1);
			i = pos[i];
		}
	}
}

int main() {
	cin >> s;
	int p1 = -1, p2 = -1;
	for (int i = 0; i < s.size(); i++) {
		ans.push_back(' ');
		if (s[i] == '(') {
			st.push(i);
		} else if (s[i] == ')') {
			pos[st.top()] = i;
			st.pop();
		}
	}
	solve(-1, s.size(), 0, s.size() - 1, 0);

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != ' ') {
			ans2.push_back(ans[i]);
		}
	}
	
	cout << ans2 << endl;
	
	return 0;
}