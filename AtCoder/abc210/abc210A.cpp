#include<iostream>
using namespace std;

int N, A, X, Y;
int main() {
	scanf("%d %d %d %d", &N, &A, &X, &Y);
	printf("%d\n", min(N, A) * X + max(N - A, 0) * Y);
	return 0;
}
