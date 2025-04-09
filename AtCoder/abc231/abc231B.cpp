#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n;
map<string, int> m;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m[s]++;
	}
	string ans = "";
	int k = 0;
	for (auto x : m) {
		if (x.second > k) {
			k = x.second;
			ans = x.first;
		}
	}
	cout << ans << endl;
	return 0;
}
