#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int T, a[200], ans;
int main(){
	scanf("%d", &T);
	for (int i = 3; i <= 360; i++) {
		if ((i - 2) * 180 % i == 0) {
			int temp = (i - 2) * 180 / i;
			if (i % 2 == 0) {
				int k;
				if (180 % i == 0) {
					k = (180 - (i / 2 - 1) * 360 / i) / 2;
				} else {
					k = 180 - (i / 2 - 1) * 360 / i;
				}
				int l = k;
				while (l <= temp) {
					if (a[l] == 0) {
						a[l] = i;
					}
					l += k;
				}
			} else {
				int k = (180 - temp) / 2;
				int l = k;
				while (l <= temp) {
					if (a[l] == 0) {
						a[l] = i;
					}
					l += k;
				}
			}
		}
	}
	for (int i = 0; i < T; i++) {
		int k;
		scanf("%d", &k);
		if (a[k] == 0) {
			printf("-1\n");
		} else {
			printf("%d\n", a[k]);
		}
	}
	return 0;
}
