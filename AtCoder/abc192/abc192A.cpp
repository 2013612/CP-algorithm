#include<iostream>
using namespace std;

int N;
int main() {
	scanf("%d", &N);
	printf("%d\n", 100 - N % 100);
	return 0;
}
