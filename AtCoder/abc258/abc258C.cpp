#include<iostream>
using namespace std;

int n, q, cur;
string s;
int main() {
	scanf("%d %d", &n, &q);
	cin >> s;
	for (int i = 0; i < q; i++) {
		int t, x;
		scanf("%d %d", &t, &x);
		if (t == 1) {
			cur = (cur - x + n) % n;
		} else {
			printf("%c\n", s[(cur + x + n - 1) % n]);
		}
	}
	return 0;
}