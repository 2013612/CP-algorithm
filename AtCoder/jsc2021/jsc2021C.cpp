#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int A, B;
int main() {
	scanf("%d %d", &A, &B);
	for (int i = B - A; i > 0; i--) {
		int div = A / i;
		if (A % i != 0) {
			div++;
		}
		if (div * i <= B && (div + 1) * i <= B) {
			printf("%d\n", i);
			return 0;
		}
	}
}
