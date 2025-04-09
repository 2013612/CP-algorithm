#include<iostream>

int n, x[100006][2], left, right, num;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x[i][0]);
		scanf("%d", &x[i][1]);
	}
	x[n][0] = 2e9 + 2;
	left = -1e9;
	for (int i = 0; i < n; i++){
		right = x[i+1][0];
		if (left < x[i][0] - x[i][1]){
			num++;
			left = x[i][0];
		} else if (x[i][0] + x[i][1] < right){
			num++;
			left = x[i][0] + x[i][1];
		} else {
			left = x[i][0];
		}
	}
	printf("%d\n", num);
	return 0;
}
