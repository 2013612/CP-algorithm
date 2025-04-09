#include<iostream>
using namespace std;

int sum_a, sum_b;

int main() {
	for (int i = 0; i < 9; i++) {
		int a;
		scanf("%d", &a);
		sum_a += a;
	}
	for (int i = 0; i < 8; i++) {
		int b;
		scanf("%d", &b);
		sum_b += b;
	}
	
	printf("%d\n", sum_a - sum_b + 1);
	
	return 0;
}