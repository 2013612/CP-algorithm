#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	printf("%d\n", (s[0] - '0') * (s[2] - '0'));
	
	return 0;
}