#include<iostream>
using namespace std;

int n, k, x;

int main() {
	scanf("%d %d %d", &n, &k, &x);
	
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		
		printf("%d ", a);
		
		if (i == k - 1) {
			printf("%d ", x);
		}
	}
	printf("\n");
	
	return 0;
}