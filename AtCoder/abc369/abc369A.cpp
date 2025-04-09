#include<iostream>
using namespace std;

int a, b, ans;
int main() {
	scanf("%d %d", &a, &b);
	
	if (a == b) {
		ans = 1;
	} else if ((a - b) % 2) {
		ans = 2;
	} else {
		ans = 3;
	}
	
	printf("%d\n", ans);
	return 0;
}