#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[200006];

void solve() {
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	s.push_back('0');
	int sum = 0;
	int j = 0;
	
	for (; j < n; j++) {
		if (s[j] == '0') {
			break;
		}
		
		sum += a[j];
		
		if (j == n - 1) {
			printf("%d\n", sum);
			return;
		}
	}
	
	a[n] = 0;
	int ans = sum;
	int mini = 1e9;
	for (int i = j; i <= n; i++) {
		if (s[i] == '0') {
			if (mini < 1e7) {
				ans -= mini;
				mini = 1e9;
			}
		} 
		ans += a[i];
		mini = min(mini, a[i]);
	}
	
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