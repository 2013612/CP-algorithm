#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int A, B;
int main() {
	scanf("%d %d", &A, &B);
	printf("%f\n", ((double)A - B) / 3 + B);
	return 0;
}
