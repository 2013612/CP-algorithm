#include<iostream>
using namespace std;

int t, r, c;
string S[2] = {"+-", "|."};

bool check(int i, int j) {
	if (i == 0 && (j == 0 || j == 1)) {
		return true;
	}
	if (i == 1 && j == 0) {
		return true;
	}
	return false;
}

int main() {
	scanf("%d", &t);
	for (int p = 1; p <= t; p++) {
		printf("Case #%d:\n", p);
		scanf("%d %d", &r, &c);
		for (int i = 0; i < 2 * r + 1; i++) {
			string t;
			for (int j = 0; j < 2 * c + 1; j++) {
				if (check(i, j)) {
					t.push_back('.');
				} else {
					t.push_back(S[i % 2][j % 2]);
				}
			}
			cout << t << endl;
		}
	}
	return 0;
}
