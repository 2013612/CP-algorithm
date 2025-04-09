#include<bits/stdc++.h>
using namespace std;

int n, r, c, a[300005];
map<pair<int, int>, int> st;
string s, ans;

int main() {
	scanf("%d %d %d", &n, &r, &c);
	cin >> s;
	
	string t = s;
	reverse(t.begin(), t.end());
	
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] == 'E') {
			y++;
		} else if (t[i] == 'S') {
			x++;
		} else if (t[i] == 'W') {
			y--;
		} else {
			x--;
		}
		
		st[{x, y}] = i;
	}
	
	for (int i = 0; i < n; i++) {
		if (st.count({r, c}) && st[{r, c}] >= i) {
			ans.push_back('1');
		} else {
			ans.push_back('0');
		}
		
		if (t[i] == 'E') {
			c++;
		} else if (t[i] == 'S') {
			r++;
		} else if (t[i] == 'W') {
			c--;
		} else {
			r--;
		}
	}
	
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	
	return 0;
}