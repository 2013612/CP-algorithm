#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s;
int main() {
	cin >> s;
	sort(s.begin(), s.end());
	cout << s << endl;
	return 0;
}
