#include<iostream>
using namespace std;

int t, x1, p1, x2, p2;
int main() {
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d", &x1, &p1);
		scanf("%d %d", &x2, &p2);
		int c1 = 0;
		int c2 = 0;
		int a = x1;
		while (a > 0) {
			a /= 10;
			c1++;
		}
		a = x2;
		while (a > 0) {
			a /= 10;
			c2++;
		}
		if (c1 + p1 > c2 + p2) {
			printf(">\n");
		} else if (c1 + p1 < c2 + p2) {
			printf("<\n");
		} else {
			while (p1 != p2) {
				if (p1 > p2) {
					p1--;
					x1 *= 10;
				} else {
					p2--;
					x2 *= 10;
				}
			}
			if (x1 == x2) {
				printf("=\n");
			} else if (x1 < x2) {
				printf("<\n");
			} else {
				printf(">\n");
			}
		}
	}
	return 0;
}
