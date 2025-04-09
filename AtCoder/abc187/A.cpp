#include<iostream>
using namespace std;

int A, B;
int main() {
	scanf("%d %d", &A, &B);
	int A1 = A/100 + A/10 % 10 + A % 10;
	int B1 = B/100 + B/10 % 10 + B % 10;
	printf("%d\n", max(A1, B1));
	return 0;
}
