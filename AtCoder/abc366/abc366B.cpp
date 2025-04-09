#include<iostream>
using namespace std;

int n, maxi;
string s[103];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int k = s[i].size();
		maxi = max(maxi, k);
	}
	
	for (int i = 0; i < maxi; i++) {
		string t;
		for (int j = n - 1; j >= 0; j--) {
			if (i < s[j].size()) {
				t.push_back(s[j][i]);
			} else {
				t.push_back('*');
			}
		}
		
		while (t.back() == '*') {
			t.pop_back();
		}
		cout << t << endl;
	}
	
	return 0;
}