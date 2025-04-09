#include<iostream>
using namespace std;

int n, ans;

int main() {
	scanf("%d", &n);
	
	if (400 % n == 0) {
		ans = 400 / n;
	} else {
		ans = -1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}