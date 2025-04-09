#include<iostream>
using namespace std;

int A, B;
int main() {
	scanf("%d %d", &A, &B);
	if (A + B >= 15 && B >= 8) {
		printf("1\n");
	} else if (A + B >= 10 && B >= 3) {
		printf("2\n");
	} else if (A + B >= 3) {
		printf("3\n");
	} else {
		printf("4\n");
	}
	return 0;
}
