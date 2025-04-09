#include<iostream>
#include<vector>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	
	for (int i = 1; i < s.size(); i++) {
		vector<string> v;
		for (int j = 0; j < s.size(); j += i) {
			v.push_back(s.substr(j, i));
		}
		
		for (int j = 0; j < v[0].size(); j++) {
			string w = "";
			for (int k = 0; k < v.size() && j < v[k].size(); k++) {
				w.push_back(v[k][j]);
			}
			if (w == t) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	
	printf("No\n");
	
	return 0;
}