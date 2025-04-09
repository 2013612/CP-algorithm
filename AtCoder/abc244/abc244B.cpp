#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans[2], x[4] = {1, 0, -1, 0}, y[4] = {0, -1, 0, 1}, dir;
string s;
int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'S') {
			ans[0] += x[dir];
			ans[1] += y[dir];
		} else {
			dir++;
			dir %= 4;
		}
	}
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}
