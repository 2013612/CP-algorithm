#include<iostream>
using namespace std;

int n, k, a;
bool x[100006];

int gcd(int a, int b){
	return a == 0? b : gcd(b%a, a);
}

int main() {
	scanf("%d %d", &n, &k);
	int r = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a);
		a = gcd(a, k);
		x[a] = true;
		if (a > r){
			r = a;
		}
	}
	int ans = 0;
	for (int i = 0; i <= r; i++){
		if (x[i]){
			ans = gcd(ans, i);
		}
	}
	if (ans == 0){
		printf("1\n");
		printf("0\n");
	} else {
		printf("%d\n", k/ans);
		for (int i = 0; i < k/ans; i++){
			printf("%d ", i*ans);
		}
		printf("\n");
	}
	return 0;
}
