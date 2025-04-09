#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s;

int main() {
	cin >> s;
	
	int t = stoi(s.substr(3));
	
	if (t < 350 && t > 0 && t != 316) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}