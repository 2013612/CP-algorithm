#include<iostream>
using namespace std;

int n, m;

string s[2003];

int main() {
	scanf("%d %d", &n, &m);
	s[0] = "1";
	for (int i = 1; i <= 10; i++) {
		string t = string(1 << (i - 1), '0');
		for (int j = 0; j < (1 << (i - 1)); j++) {
			s[j + (1 << (i - 1))] = s[j] + t;
			s[j] = s[j] + s[j];
		}
	}
	
	for (int i = 0; i < (1 << n) - 1; i++) {
		for (int j = 0; j < (1 << m) - 1; j++) {
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}