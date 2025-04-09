#include<iostream>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	string s;
	cin >> s;
	
	bool can = s.size() & 1;
	
	for (int i = 0; i < n; i++) {
		if ((i < n / 2 && s[i] != '1') || (i == n / 2 && s[i] != '/') || i > n / 2 && s[i] != '2') {
			can = false;
		}
	}
	
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}