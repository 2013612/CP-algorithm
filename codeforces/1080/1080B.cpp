#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int Q, l, r;
int main(){
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int ans = 0;
		scanf("%d %d", &l, &r);
		if (l % 2) {
			if (r % 2) {
				ans += (r - l) / 2;
				ans -= r;
			} else {
				ans += (r - l + 1) / 2;
			}
		} else {
			if (r % 2) {
				ans -= (r - l + 1) / 2;
			} else {
				ans -= (r - l) / 2;
				ans += r;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
