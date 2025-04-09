#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
int main() {
	scanf("%d", &n);
		for (int j = 1;; j++) {
			if (j*j >= n) {
				for (int k = 0; k <= n/j; k++) {
					int num = (n/j - k) *j;
					for (int l = 0; l < j; l++) {
						if (num + l + 1<= n) {
							printf("%d ", num + l + 1);
						}
					}
				}
				break;
			}
		}
	return 0;
}
