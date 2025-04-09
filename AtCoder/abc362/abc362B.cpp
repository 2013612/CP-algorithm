#include<iostream>
using namespace std;

int x[3], y[3];
int main() {
	scanf("%d %d", &x[0], &y[0]);
	scanf("%d %d", &x[1], &y[1]);
	scanf("%d %d", &x[2], &y[2]);
	
	int a = (x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]);
	int b = (x[0] - x[2]) * (x[0] - x[2]) + (y[0] - y[2]) * (y[0] - y[2]);
	int c = (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]);
	
	if (a > b) {
		swap(a, b);
	}
	if (b > c) {
		swap(b, c);
	}
	
	if (a + b == c) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}