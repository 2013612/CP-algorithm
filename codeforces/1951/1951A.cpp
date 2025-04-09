#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[100006], ans;

void solve() {
	scanf("%d", &n);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			cnt++;
		}
	}
	
	if (cnt == 2) {
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == '1' && s[i + 1] == '1') {
				printf("NO\n");
				return;
			}
		}
	}
	
	if (cnt % 2 == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}