#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int main() {
	scanf("%d %d", &N, &K);
	printf("%d\n", (N * (N + 1) * K / 2) * 100 + (K * (K + 1) * N / 2));
	return 0;
}
