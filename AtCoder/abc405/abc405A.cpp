#include<iostream>
using namespace std;

int r, x;

int main() {
	scanf("%d %d", &r, &x);
	
	if ((x == 1 && r >= 1600 && r < 3000) || (x == 2 && r >= 1200 && r < 2400)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}