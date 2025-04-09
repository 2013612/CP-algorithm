#include<iostream>
using namespace std;

int n, k, a[200006], ans;

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[(i + k) % n]);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
	printf("\n");
	return 0;
}