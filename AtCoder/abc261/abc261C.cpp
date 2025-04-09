#include<iostream>
#include<unordered_map>
using namespace std;

int n, ans;
unordered_map<string, int> um;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (um.count(s) == 0) {
			cout << s << endl;
		} else {
			cout << s << '(' << um[s] << ')' << endl;
		}
		
		um[s]++;
	}
	return 0;
}