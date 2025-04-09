#include<iostream>
using namespace std;

int l1, r1, l2, r2, ans;
int main() {
	scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
	if (r1 <= l2) {
		ans = 0;
	} else if (l2 >= l1) {
		if (r2 >= r1) {
			ans = r1 - l2;
		} else {
			ans = r2 - l2;
		}
	} else if (r2 > l1) {
		if (r2 >= r1) {
			ans = r1 - l1;
		} else {
			ans = r2 - l1;
		}
	} else {
		ans = 0;
	}
	printf("%d\n", ans);
	return 0;
}