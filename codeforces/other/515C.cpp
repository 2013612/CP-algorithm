#include<iostream>
using namespace std;

int N, a[103];
int main() {
	scanf("%d", &N);
	long long temp;
	scanf("%lld", &temp);
	for (int i = 0; i < N; i++) {
		int k = temp % 10;
		//9cout << temp << endl;
		if (k == 2 || k == 3 || k == 5 || k == 7) {
			a[k]++;
		} else if (k == 4) {
			a[2] += 2;
			a[3]++;
		} else if (k == 6) {
			a[5]++;
			a[3]++;
		} else if (k == 8) {
			a[7]++;
			a[2] += 3;
		} else if (k == 9) {
			a[7]++;
			a[3] += 2;
			a[2]++;
		}
		temp /= 10;
	}
	for (int i = 9; i >= 2; i--) {
		for (int j = 0; j < a[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}
