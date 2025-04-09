#include<iostream>
using namespace std;

int N, ans;
string s;
int main() {
	scanf("%d", &N);
	cin >> s;
	if (s[N - 1] == 'o') {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
