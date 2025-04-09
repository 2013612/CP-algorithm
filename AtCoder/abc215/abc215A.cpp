#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string s = "Hello,World!";
	string s2;
	cin >> s2;
	if (s == s2) {
		printf("AC\n");
	} else {
		printf("WA\n");
	}
	return 0;
}
