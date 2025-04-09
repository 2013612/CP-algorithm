#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, p[200006], q[200006];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
		q[p[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", q[i]);
	}
	printf("\n");
	return 0;
}
