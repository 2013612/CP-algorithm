#include<bits/stdc++.h>
using namespace std;

int n;
string ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < (n - 1) / 2; i++) {
		ans.push_back('-');
	}
	
	ans.push_back('=');
	
	if (n % 2 == 0) {
		ans.push_back('=');
	}
	
	for (int i = 0; i < (n - 1) / 2; i++) {
		ans.push_back('-');
	}
	
	cout << ans << endl;
	
	return 0;
}