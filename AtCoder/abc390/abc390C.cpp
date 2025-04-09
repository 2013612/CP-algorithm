#include<iostream>
using namespace std;

int h, w, min_i = 1e9, min_j = 1e9, max_i, max_j;
string s[1003];

int main() {
	scanf("%d %d", &h, &w);
	
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '#') {
				min_i = min(min_i, i);
				min_j = min(min_j, j);
				max_i = max(max_i, i);
				max_j = max(max_j, j);
			}
		}
	}
	
	for (int i = min_i; i <= max_i; i++) {
		for (int j = min_j; j <= max_j; j++) {
			if (s[i][j] == '.') {
				printf("No\n");
				return 0;
			}
		}
	}
	
	printf("Yes\n");
	
	return 0;
}