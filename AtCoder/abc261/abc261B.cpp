#include<iostream>
using namespace std;

int n;
string s[1003];
bool ans = true;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i][j] == 'W' && s[j][i] == 'L') {
				continue;
			} else if (s[i][j] == 'L' && s[j][i] == 'W') {
				continue;
			} else if (s[i][j] == 'D' && s[j][i] == 'D') {
				continue;
			}
			ans = false;
		}
	}
	
	if (ans) {
		printf("correct\n");
	} else {
		printf("incorrect\n");
	}
	return 0;
}