#include<iostream>
using namespace std;

void solve() {
	int r, c;
	scanf("%d %d", &r, &c);
	string s[103];
	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}
	if (r == 1 || c == 1) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (s[i][j] == '^') {
					printf("Impossible\n");
					return;
				}
			}
		}
		printf("Possible\n");
		for (int i = 0; i < r; i++) {
			cout << s[i] << endl;
		}
		return;
	}
	printf("Possible\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("^");
		}
		printf("\n");
	}
}

int main() {
	freopen("second_friend_input.txt", "r", stdin);
	freopen("second_friend_output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}