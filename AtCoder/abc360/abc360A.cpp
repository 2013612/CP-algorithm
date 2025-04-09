#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'R') {
			printf("Yes\n");
			break;
		} else if (s[i] == 'M') {
			printf("No\n");
			break;
		}
	}
	
	return 0;
}