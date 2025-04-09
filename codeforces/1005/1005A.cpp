#include<iostream>
using namespace std;

int n, a[1004], b[1004];
int main(){
	scanf("%d", &n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i-1] >= a[i]) {
			b[j] = a[i-1];
			j++;
		}
	}
	printf("%d\n", j);
	for (int i = 0; i < j; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
