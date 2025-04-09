#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, ans;
int main() {
	scanf("%d", &n);
	if (n >= 5 || n == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
