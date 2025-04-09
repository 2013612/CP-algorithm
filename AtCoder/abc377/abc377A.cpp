#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s == "ABC") {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}