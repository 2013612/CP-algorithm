#include<iostream>
using namespace std;

int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	if (B == 0) {
		printf("Gold\n");
	} else if (A == 0) {
		printf("Silver\n");
	} else {
		printf("Alloy\n");
	}
	return 0;
}
