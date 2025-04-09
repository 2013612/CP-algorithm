#include<iostream>
using namespace std;
const int M = 1e9 + 7;

int n, b[3];
long long ans = 1;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		int cnt = 0;
		if (a == b[0]) cnt++;
		if (a == b[1]) cnt++;
		if (a == b[2]) cnt++;
		ans = (ans * cnt) % M;
		if (a == b[0]) {
			b[0]++;
		} else if (a == b[1]) {
			b[1]++;
		} else if (a == b[2]) {
			b[2]++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
