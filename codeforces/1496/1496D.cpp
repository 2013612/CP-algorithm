#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, a[100006], maxi1, maxi2, num1, num2;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	maxi1 = 1;
	num1 = 1;
	int cur = 1;
	for (int i = 1; i < N; i++) {
		if (a[i] > a[i - 1]) {
			cur++;
		} else {
			if (cur > maxi1) {
				maxi1 = cur;
				num1 = 1;
			} else if (cur == maxi1) {
				num1++;
			}
			cur = 1;
		}
	}
	if (cur > maxi1) {
		maxi1 = cur;
		num1 = 1;
	} else if (cur == maxi1) {
		num1++;
	}
	maxi2 = 1;
	num2 = 1;
	cur = 1;
	for (int i = N - 2; i >= 0; i--) {
		if (a[i + 1] < a[i]) {
			cur++;
		} else {
			if (cur > maxi2) {
				maxi2 = cur;
				num2 = 1;
			} else if (cur == maxi2) {
				num2++;
			}
			cur = 1;
		}
	}
	if (cur > maxi2) {
		maxi2 = cur;
		num2 = 1;
	} else if (cur == maxi2) {
		num2++;
	}
	//cout << maxi1 << " " << maxi2 << endl;
	if (maxi1 == maxi2) {
		if (num1 + num2 == 1) {
			printf("1\n");
		} else if (num1 == num2 && num1 == 1) {
			int cur = 1;
			bool success = true;
			for (int i = 1; i < N; i++) {
				if (a[i] > a[i - 1]) {
					cur++;
				}
				if (cur == maxi1) {
					for (int j = i + 1; j < maxi1; j++) {
						if (a[j] > a[j - 1]) {
							success = false;
							break;
						}
					}
					break;
				}
			}
			if (success) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		} else {
			printf("0\n");
		}
	} else {
		if (maxi1 > maxi2 && num1 == 1 && maxi1 % 2 == 1) {
			printf("1\n");
		} else if (maxi2 > maxi1 && num2 == 1 && maxi2 % 2 == 1) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}
