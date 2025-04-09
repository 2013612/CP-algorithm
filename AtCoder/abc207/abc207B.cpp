#include<iostream>
using namespace std;

int A, B, C, D;
int main() {
	scanf("%d %d %d %d", &A, &B, &C, &D);
	if (D * C <= B) {
		printf("-1\n");
		return 0;
	}
	int ans = A / (D * C - B);
	if (A % (D * C - B) != 0) {
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
