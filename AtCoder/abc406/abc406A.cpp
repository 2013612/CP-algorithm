#include<iostream>
using namespace std;

int a, b, c, d;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if (a > c || (a == c && b > d)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}