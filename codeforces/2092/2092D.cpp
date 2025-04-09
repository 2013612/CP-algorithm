#include<bits/stdc++.h>
using namespace std;

int n, a[3];
string s, t;
vector<int> ans;

bool eq() {
	return a[0] == a[1] && a[1] == a[2];
}

void ins(int mode) {
	int m = t.size();
	
	char t1 = 'A' + (mode + 1) % 3;
	char t2 = 'A' + (mode + 2) % 3;
	
	for (int i = 0; i < m - 1; i++) {
		if ((t[i] == t1 && t[i + 1] == t2) || (t[i] == t2 && t[i + 1] == t1)) {
			ans.push_back(i + 1);
			a[mode]++;
			t.insert(t.begin() + i + 1, (char)('A' + mode));
			break;
		}
	}
}

void solve() {
	scanf("%d", &n);
	cin >> s;
	a[0] = a[1] = a[2] = 0;
	
	ans.clear();
	t = "";
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			a[0]++;
			t.push_back('A');
		} else if (s[i] == 'I') {
			a[1]++;
			t.push_back('B');
		} else {
			a[2]++;
			t.push_back('C');
		}
	}
	
	
	{
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			cnt += a[i] == 0;
		}
		
		if (cnt >= 2) {
			printf("-1\n");
			return;
		}
	}
	
	while (!eq()) {
		int sum = 0;
		int mode = 0;
		
		if (a[1] < a[0]) {
			mode = 1;
		} else if (a[2] < a[0]) {
			mode = 2;
		}
		
		int m = t.size();
		
		ins(mode);
		
		sum -= mode;
		
		if (t.size() != m) {
			continue;
		}
		
		if (a[(mode + 1) % 3] < a[(mode + 2) % 3]) {
			mode = (mode + 1) % 3;
		} else {
			mode = (mode + 2) % 3;
		}
		
		ins(mode);
		
		sum -= mode;
		
		if (t.size() != m) {
			continue;
		}
		
		ins(3 - mode);
	}
	
	printf("%d\n", ans.size());
	for (auto x: ans) {
		printf("%d\n", x);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}