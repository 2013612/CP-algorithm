#include<iostream>
using namespace std;

int N, ans;
string s[203], t[203], ss[203], tt[203], tr[203], tr2[203], tr3[203];

void clear() {
	string a;
	for (int i = 0; i < N; i++) {
		a.push_back('.');
	}
	for (int i = 0; i < N; i++) {
		ss[i] = a;
		tt[i] = a;
		tr[i] = a;
		tr2[i] = a;
		tr3[i] = a;
	}
}

void cleartt() {
	string a;
	for (int i = 0; i < N; i++) {
		a.push_back('.');
	}
	for (int i = 0; i < N; i++) {
		tt[i] = a;
	}
}


int main() {
	scanf("%d", &N);
	clear();
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	int minx = 1e9, miny = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j] == '#') {
				minx = min(minx, i);
				miny = min(miny, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j] == '#') {
				ss[i - minx][j - miny] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	bool can = false;
	minx = 1e9, miny = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (t[i][j] == '#') {
				minx = min(minx, i);
				miny = min(miny, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (t[i][j] == '#') {
				tt[i - minx][j - miny] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (ss[i] != tt[i]) {
			break;
		}
		if (i == N - 1) {
			can = true;
		}
	}
	
	cleartt();
	minx = 1e9, miny = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (t[i][j] == '#') {
				tr[j][N - i - 1] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr[i][j] == '#') {
				minx = min(minx, i);
				miny = min(miny, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr[i][j] == '#') {
				tt[i - minx][j - miny] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (ss[i] != tt[i]) {
			break;
		}
		if (i == N - 1) {
			can = true;
		}
	}
	
	cleartt();
	minx = 1e9, miny = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr[i][j] == '#') {
				tr2[j][N - i - 1] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr2[i][j] == '#') {
				minx = min(minx, i);
				miny = min(miny, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr2[i][j] == '#') {
				tt[i - minx][j - miny] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (ss[i] != tt[i]) {
			break;
		}
		if (i == N - 1) {
			can = true;
		}
	}
	
	cleartt();
	minx = 1e9, miny = 1e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr2[i][j] == '#') {
				tr3[j][N - i - 1] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr3[i][j] == '#') {
				minx = min(minx, i);
				miny = min(miny, j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tr3[i][j] == '#') {
				tt[i - minx][j - miny] = '#';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (ss[i] != tt[i]) {
			break;
		}
		if (i == N - 1) {
			can = true;
		}
	}

	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
