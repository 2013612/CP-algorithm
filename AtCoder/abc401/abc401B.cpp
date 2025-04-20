#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
bool isLogin;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		if (s == "login") {
			isLogin = true;
		} else if (s == "logout") {
			isLogin = false;
		} else if (s == "private") {
			if (!isLogin) {
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}