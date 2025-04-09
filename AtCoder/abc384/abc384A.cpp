#include<iostream>
using namespace std;

int main() {
	int n;
	char c1, c2;
	
	scanf("%d %c %c", &n, &c1, &c2);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != c1) {
			s[i] = c2;
		}
	}
	
	cout << s << endl;
	
	return 0;
}