#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

long long T, N, M, p[10], q[10];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		p[0] = p[1] = q[0] = q[1] = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			p[temp % 2]++;
		}
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			int temp;
			scanf("%d", &temp);
			q[temp % 2]++;
		}
		printf("%lld\n", p[0]*q[0] + p[1]*q[1]); 
	}
	return 0;
}
