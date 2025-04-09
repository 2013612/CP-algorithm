#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a, b, c, d, ans;
int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a * 100 + b <= c * 100 + d) {
		printf("Takahashi\n");
	} else {
		printf("Aoki\n");
	}
	return 0;
}
