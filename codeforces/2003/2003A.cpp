#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

void solve() {
	scanf("%d", &n);
	string s;
	cin >> s;
	
	if (s[0] != s.back()) {
		printf("Yes\n");
	} else {
		printf("No\n");
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