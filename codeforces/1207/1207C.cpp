#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long T, N, a, b, ans;
bool up = false;
char now = '0';
char road[300006];
int main() {
	scanf("%d", &T);
	for(int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &a, &b);
		scanf("%s", road);
		ans = 0;
		up = false;
		now = '0';
		for (int j = 0; j < N; j++) {
			for (int k = j; k < N; k++) {
				if (road[k] != now) {
					if (!up && now == '0') {
						j = k;
						now = '1';
						up = true;
						ans += a;
					} else if (up && now == '0') {
						if (2 * a < (k - j - 1) * b) {
							ans += 2 * a;
							//cout << "!" << ans << " " << j << k << endl;
						} else {
							ans += (k - j - 1) * b;
							//cout << "@" << ans << endl;
						}
						j = k;
						now = '1';
					} else if (up && now == '1') {
						ans += (k - j + 1) * b;
						j = k;
						now = '0';
					}
				}
			}
		}
		if (up) {
			ans += a;
		}
		ans += (N + 1) * b + N * a;
		printf("%lld\n", ans);
	}
	return 0;
}
