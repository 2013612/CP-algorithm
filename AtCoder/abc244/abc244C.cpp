#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, t = -1;
set<int> s;
int cur = 1;
int main() {
	scanf("%d", &n);
	while (t != 0) {
		while (s.count(cur)) {
			cur++;
		}
		cout << cur << endl;
		cin >> t;
		s.insert(cur);
		s.insert(t);
	}
	return 0;
}
