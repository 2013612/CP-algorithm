#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a, b;

int main() {
	scanf("%d %d", &a, &b);
	
	for (int i = 0; i <= 9; i++) {
		if (i != a + b) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}