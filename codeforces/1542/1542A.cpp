#include<iostream>
using namespace std;

int N, odd, even, T;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		odd = even = 0;
		for (int j = 0; j < 2 * N; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp & 1) {
				odd++;
			} else {
				even++;
			}
		}
		if (odd == even) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
