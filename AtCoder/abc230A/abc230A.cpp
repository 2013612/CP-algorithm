#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
int main() {
	scanf("%d", &n);
	printf("AGC0");
	if (n < 10) {
		printf("0");
	}
	printf("%d\n", n >= 42 ? n + 1 : n);
	return 0;
}
