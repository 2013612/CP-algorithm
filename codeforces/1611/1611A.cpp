#include<iostream>
using namespace std;

int ans, t, n;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			printf("0\n");
		} else {
			bool e = false;
			bool fe = false;
			int t = n;
			while (t > 0) {
				if (t % 2 == 0) {
					e = true;
				}
				if (t < 10 && t % 2 == 0) {
					fe = true;
				}
				t /= 10;
			}
			if (fe) {
				printf("1\n");
			} else if (e) {
				printf("2\n");
			} else {
				printf("-1\n");
			}
		}
	}
}
