#include<iostream>
using namespace std;

int t, n, grundy[103];
int main() {
	scanf("%d", &t);
	grundy[2] = grundy[3] = 1;
	grundy[4] = 2;
	for (int i = 5; i <= 100; i++) {
		bool a[4] = {false, false, false, false};
		a[grundy[i - 2]] = true;
		a[grundy[i - 3]] = true;
		a[grundy[i - 5]] = true;
		for (int j = 0; j < 4; j++) {
			if (!a[j]) {
				grundy[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (grundy[n] == 0) {
			printf("Second\n");
		} else {
			printf("First\n");
		}
	}
	return 0;
}