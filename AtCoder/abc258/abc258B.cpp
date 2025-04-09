#include<iostream>
using namespace std;

int n;
string s[103];
int x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 8; k++) {
				long long temp = 0;
				for (int l = 0; l < n; l++) {
					int x1 = (i + x[k] * l + n) % n;
					int y1 = (j + y[k] * l + n) % n;
					temp = temp * 10 + s[x1][y1] - '0';
				}
				ans = max(ans, temp);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}