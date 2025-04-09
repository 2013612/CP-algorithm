#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a, b, c, ans;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	if (min(a, c) <= b && b <= max(a, c)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}