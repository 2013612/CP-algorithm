#include<iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		sum += t;
	}
	printf("%d\n", sum);
	return 0;
}
