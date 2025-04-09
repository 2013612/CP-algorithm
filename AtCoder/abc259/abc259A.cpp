#include<iostream>
using namespace std;

int n, m, x, t, d;
int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &t, &d);
	printf("%d\n", t - d * max(x - m, 0));
	return 0;
}