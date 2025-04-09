#include<iostream>
using namespace std;

int n, q, a[200006], sum;
string s;

int main() {
	scanf("%d %d", &n, &q);
	cin >> s;
	for (int i = 0; i < n - 2; i++) {
		if (s.substr(i, 3) == "ABC") {
			sum++;
			a[i]++;
			a[i + 1]++;
			a[i + 2]++;
		}
	}
	
	for (int i = 0; i < q; i++) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		x--;
		for (int j = 0; j < 3; j++) {
			if (x - 2 + j < 0 || x + j >= n) {
				continue;
			}
			if (s.substr(x - 2 + j, 3) == "ABC") {
				sum--;
			}
		}
		s[x] = c;
		for (int j = 0; j < 3; j++) {
			if (x - 2 + j < 0 || x + j >= n) {
				continue;
			}
			if (s.substr(x - 2 + j, 3) == "ABC") {
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}