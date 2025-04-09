#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, T, X, Y, D, ans;

int abs (int x) {
	return x < 0? -x: x;
}

int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d", &N, &X, &Y, &D);
		if ((Y - X) % D == 0) {
			printf("%d\n", abs(Y - X)/D);
		} else {
			if ((Y - 1) % D == 0 || (N - Y) % D == 0) {
				int temp1 = 2000000000;
				int temp2 = 2000000000;
				if ((Y - 1) % D == 0) {
					temp1 = (Y - 1) / D;
					temp1 += (X - 1) / D;
					if ((X - 1) % D != 0) {
						temp1++;
					} 
				}
				if ((N - Y) % D == 0) {
					temp2 = (N - Y) / D;
					temp2 += (N - X) / D;
					if ((N - X) % D != 0) {
						temp2++;
					}
				}
				printf("%d\n", min(temp1, temp2));
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}
