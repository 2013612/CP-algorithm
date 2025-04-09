#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, ans;

int f(int x) {
	return x * x + 2 * x + 3;
}

int main() {
	scanf("%d", &t);
	printf("%d\n", f(f(f(t) + t) + f(f(t))));
	return 0;
}
