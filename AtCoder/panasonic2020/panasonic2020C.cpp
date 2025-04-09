#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

long long A, B, C;
int main() {
	scanf("%lld %lld %lld", &A, &B, &C);
	//cout << sqrt(A) << " " << sqrt(B) << " " << sqrt(C) << " " << sqrt(A) + sqrt(B) << endl; 
	if (C < A + B) {
		printf("No\n");
		return 0;
	}
	if (4*A*B < (C - A - B)*(C - A - B)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
