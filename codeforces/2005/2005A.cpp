#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char c[5] = {'a', 'e', 'i', 'o', 'u'};
int a[200006], ans;

void solve() {
	int n;
	scanf("%d", &n);
	
	string s;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n / 5; j++) {
			s.push_back(c[i]);
		}
		if (n % 5 > i) {
			s.push_back(c[i]);
		}
	}
	
	cout << s << endl;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}