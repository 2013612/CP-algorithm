#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;
bool can;

int main() {
	scanf("%d", &n);
	
	string s, t;
	
	cin >> s;
	cin >> t;
	
	if (s.size() > t.size()) {
		swap(s, t);
	}
	
	if (s.size() == t.size()) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) {
				ans++;
			}
		}
		
		if (ans <= 1) {
			can = true;
		}
	} else if (s.size() + 1 == t.size()) {
		int j = 0;
		
		for (int i = 0; i < t.size(); i++) {
			if (s[j] == t[i]) {
				j++;
			}
		}
		
		if (j == s.size()) {
			can = true;
		}
	}
	
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}