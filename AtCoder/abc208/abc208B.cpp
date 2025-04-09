#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans, a[21];
int main() {
	scanf("%d", &N);
	a[0] = 1;
	for (int i = 1; i <= 10; i++) {
		a[i] = a[i - 1] * i;
	}
	for (int i = 10; i >= 1; ) {
		if (a[i] > N) {
			i--;
		} else {
			N -= a[i];
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
