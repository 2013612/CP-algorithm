#include<iostream>
using namespace std;

int main() {
	string s[103];
	int n;
	scanf("%d", &n);
	bool safe = true;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 7; j++) {
			string t;
			string t2;
			for (int k = j; k < j + 8; k++) {
				t.push_back(s[i][k]);
				t2.push_back(s[k][i]);
			}
			if (t == "minotaur" || t2 == "minotaur") {
				safe = false;
			}
		}
	}
	if (safe) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
