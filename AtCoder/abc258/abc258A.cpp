#include<iostream>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	if (k % 60 < 10) {
		printf("%d:0%d", 21 + k / 60, k % 60);
	} else {
		printf("%d:%d", 21 + k / 60, k % 60);
	}
	return 0;
}