#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, T, ans;

int main() {
	scanf("%d", &N);
	ans = N / 2;
	if (N % 2 == 1) {
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
