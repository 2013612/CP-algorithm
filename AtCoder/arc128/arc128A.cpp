#include<iostream>
using namespace std;

int N, a[200006];
bool inc = true;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	a[N] = 2e9;
	for (int i = 0; i < N; i++) {
		if ((inc && a[i + 1] < a[i]) || (!inc && a[i + 1] >= a[i])) {
			printf("1 ");
			inc = !inc;
		} else {
			printf("0 ");
		}
	}
	printf("\n");
	return 0;
}
