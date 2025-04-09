#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int a, b, ans;
int main() {
	scanf("%d %d", &a, &b);
	if (a == b) {
		ans = a;
	} else {
		ans = 3 - a - b;
	}
	printf("%d\n", ans);
	return 0;
}
