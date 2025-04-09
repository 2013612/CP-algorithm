#include<iostream>
using namespace std;

int A, B, C;
int main() {
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", max(A + B, max(B + C, A + C)));
	return 0;
}
