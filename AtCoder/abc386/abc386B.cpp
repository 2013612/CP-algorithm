#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], ans;

int main() {
	string s;
	
	cin >> s;
	
	bool b = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (b) {
				b = false;
			} else {
				b = true;
				ans++;
			}
		} else {
			b = false;
			ans++;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}