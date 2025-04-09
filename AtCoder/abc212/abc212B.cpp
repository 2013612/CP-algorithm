#include<iostream>
using namespace std;

string S;
int main() {
	cin >> S;
	int a, b, c, d;
	a = S[0] - '0';
	b = S[1] - '0';
	c = S[2] - '0';
	d = S[3] - '0';
	if (S[0] == S[1] && S[1] == S[2] && S[2] == S[3]) {
		printf("Weak\n");
	} else {
		if (b == (a + 1) % 10 && c == (b + 1) % 10 && d == (c + 1) % 10) {
			printf("Weak\n");
		} else {
			printf("Strong\n");
		}
	}
	return 0;
}
