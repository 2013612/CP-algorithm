#include<iostream>
using namespace std;

int r;
int main() {
	scanf("%d", &r);
	
	printf("%d\n", (300 - r - 1) % 100 + 1);
	
	return 0;
}