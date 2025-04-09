#include<iostream>

int main() {
	for (int i = 0; i < 19; i++) {
		char a;
		int b;
		scanf("%c %d", &a, &b);
		printf("%d %d\n", b, a - 'A' + 1);
	}
	return 0;
}
