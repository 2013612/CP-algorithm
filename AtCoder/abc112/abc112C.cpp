#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, x[103], y[103], h[103];

int abs(int a) {
	return a >= 0? a: -a;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x[i], &y[i], &h[i]);
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			int temp = h[0] + abs(x[0] - i) + abs(y[0] - j);
			if (temp < 1) {
				continue;
			}
			for (int k = 0; k < N; k++) {
				if (temp - abs(x[k] - i) - abs(y[k] - j) < 0) {
					if (h[k] != 0) {
						break;
					}
				} else {
					if (h[k] + abs(x[k] - i) + abs(y[k] - j) != temp) {
						break;
					}
				}
				if (k == N - 1) {
					printf("%d %d %d\n", i, j, temp);
				}
			}
		}
	}
	return 0;
}
