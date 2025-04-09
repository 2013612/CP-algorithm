#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a, b;
int main() {
	scanf("%d %d", &a, &b);
	if (b - a == 1 || (a == 1 && b == 10)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
