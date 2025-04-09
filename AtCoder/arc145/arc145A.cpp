#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
string s;
int main() {
	scanf("%d", &n);
	cin >> s;
	if (s[0] != s.back()) {
		if (s[0] == 'A' || s == "BA") {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");
	return 0;
}