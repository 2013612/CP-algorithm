#include<iostream>
using namespace std;

int n;
string a[103], b[103];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j]) {
				printf("%d %d\n", i + 1, j + 1);
				break;
			}
		}
	}
	
	return 0;
}