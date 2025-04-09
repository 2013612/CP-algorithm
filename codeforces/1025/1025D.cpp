#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, a[1004][2], b[1004];

int gcd(int a,int b){
	return a == 0? b : gcd(b%a,a);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i][0]);
	}
	int group = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (gcd(a[i][0], a[j][0]) >= 2) {
				a[i][1]++;
				a[j][1]++;
				if (b[i] == 0 && b[j] == 0) {
					b[i] = b[j] = group;
					group++;
				} else if (b[i] == 0) {
					b[i] = b[j];
				} else if (b[j] == 0) {
					b[j] = b[i];
				}
				if (b[i] != 0 && b[j] != 0) {
					int k_min = min(b[i], b[j]);
					int k_max = max(b[i], b[j]);
					for (int p = 0; p < n; p++) {
						if (b[p] == k_max) {
							b[p] = k_min;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i][1] == 0) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] != 1) {
			printf("No\n");
			return 0;
		}
	}
	int edge = 0;
	for (int i = 0; i < n; i++) {
		if (a[i][1] >= 3) {
			edge += 3;
		} else {
			edge += a[i][1];
		}
	}
	if (edge >= 2*(n - 1)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
