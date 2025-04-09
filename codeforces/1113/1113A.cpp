#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, V, ans, A;
int main(){
	scanf("%d %d", &N, &V);
	if (N - 1 <= V) {
		printf("%d\n", N - 1);
		return 0;
	}
	A = N - V;
	ans = A * (A + 1)/2 + V - 1;
	printf("%d\n", ans);
	return 0;
}
