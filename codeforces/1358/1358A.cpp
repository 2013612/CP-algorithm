#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, M;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%d\n", (N * M + 1)/2);
	}
	return 0;
}
