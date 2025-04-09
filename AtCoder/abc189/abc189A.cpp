#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string S;
int main() {
	cin >> S;
	if (S[0] == S[1] && S[1] == S[2]) {
		printf("Won\n");
	} else {
		printf("Lost\n");
	}
	return 0;
}
