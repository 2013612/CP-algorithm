#include<iostream>
using namespace std;

int main() {
	int y;
	scanf("%d", &y);
	
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
		printf("366\n");
	} else {
		printf("365\n");
	}
	
	return 0;
}