#include<iostream>
using namespace std;

int n, m, ans;
int main() {
	scanf("%d %d", &n, &m);
	if (n >= m) {
		printf("%d\n", n - m);
	} else {
		while (true) {
			if (m <= n) {
				break;
			}
			if (m % 2 == 1) {
				m++;
			} else {
				m /= 2;
			}
			ans++; 
		}
		ans += n - m;
		printf("%d\n", ans);
	}
	return 0;
}
