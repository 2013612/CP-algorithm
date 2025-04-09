#include<iostream>
using namespace std;

int N;
double ans;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N - 1; i++) {
		ans += (double)N / i;
	}
	printf("%.10f\n", ans);
	return 0;
}
