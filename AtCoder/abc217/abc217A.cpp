#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string S, T;
int main() {
	cin >> S >> T;
	if (S < T) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
