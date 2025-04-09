#include<iostream>
using namespace std;

int A, B;
int main() {
	scanf("%d %d", &A, &B);
	printf("%.5f\n", (double) (A - B) / A * 100);
	return 0;
}
