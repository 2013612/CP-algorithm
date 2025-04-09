#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, L, R, ans, a[200006], b[200006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &L, &R);
		ans = 0;
		for (int j = 1; j <= N; j++) {
			a[j] = b[j] = 0;
		}
		for (int j = 0; j < L; j++) {
			int temp;
			scanf("%d", &temp);
			a[temp]++;
		}
		for (int j = 0; j < R; j++) {
			int temp;
			scanf("%d", &temp);
			if (a[temp] > 0) {
				a[temp]--;
			} else {
				b[temp]++;
			}
		}
		int l_even = 0;
		int l_single = 0;
		int r_even = 0;
		int r_single = 0;
		for (int j = 1; j <= N; j++) {
			l_single += a[j] % 2;
			r_single += b[j] % 2;
			l_even += a[j] - a[j] % 2;
			r_even += b[j] - b[j] % 2;
		}
		if (l_single + l_even > r_single + r_even) {
			int temp = l_single;
			l_single = r_single;
			r_single = temp;
			temp = l_even;
			l_even = r_even;
			r_even = temp;
		}
		//printf("%d %d %d %d\n", l_single, l_even, r_single, r_even);
		if (r_single >= l_single + l_even) {
			ans += r_single;
			ans += r_even / 2;
		} else {
			ans += (l_single + l_even + r_single + r_even) / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
