#include<iostream>
#include<vector>
using namespace std;

vector<string> solve(int n) {
	if (n == 0) {
		vector<string> v(1, "#");
		return v;
	}
	
	vector<string> v = solve(n - 1);
	vector<string> res;
	for (int i = 0; i < v.size(); i++) {
		string t = v[i] + v[i] + v[i];
		res.push_back(t);
	}
	for (int i = 0; i < v.size(); i++) {
		string t = v[i] + string(v[i].size(), '.') + v[i];
		res.push_back(t);
	}
	for (int i = 0; i < v.size(); i++) {
		string t = v[i] + v[i] + v[i];
		res.push_back(t);
	}
	
	return res;
}

int main() {
	int n;
	scanf("%d", &n);

	auto ans = solve(n);
	for (auto x: ans) {
		cout << x << endl;
	}
	
	return 0;
}