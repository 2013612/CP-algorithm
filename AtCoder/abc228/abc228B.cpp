#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans, a[100006], X;
bool b[100006];
int main() {
	scanf("%d %d", &N, &X);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	while (!b[X]) {
		b[X] = true;
		ans++;
		X = a[X];
	}
	printf("%d\n", ans);
	return 0;
}
