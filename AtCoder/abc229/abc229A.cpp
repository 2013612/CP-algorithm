#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if ((a[0] == '.' && b[1] == '.') || (a[1] == '.' && b[0] == '.')) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
	return 0;
}
