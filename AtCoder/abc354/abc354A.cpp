#include<iostream>
using namespace std;

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 1; i < 32; i++) {
		if (1 << i > h + 1) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}