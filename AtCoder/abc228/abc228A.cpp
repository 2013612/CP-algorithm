#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a, b, c;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	if (b < a) {
		b += 24;
	}
	if (c < a) {
		c += 24;
	}
	if (c >= a && c < b) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
