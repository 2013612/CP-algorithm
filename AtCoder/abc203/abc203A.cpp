#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int a, b, c;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	if (a == b) {
		printf("%d\n", c);
	} else if (a == c) {
		printf("%d\n", b);
	} else if (b == c) {
		printf("%d\n", a);
	} else {
		printf("0\n");
	}
	return 0;
}
