#include<iostream>
using namespace std;

int a, b;
int main() {
	scanf("%d %d", &a, &b);
	int ans;
	if (a == b) {
		ans = -1;
	} else {
		ans = 6 - a - b;
	}
	
	printf("%d\n", ans);
	
	return 0;
}