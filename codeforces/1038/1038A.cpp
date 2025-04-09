#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans, K, A[30];
string S;
int main(){
	scanf("%d %d", &N, &K);
	cin >> S;
	for (int i = 0; i < N; i++) {
		A[S[i] - 'A']++;
	}
	ans = 10000000;
	for (int i = 0; i < K; i++) {
		ans = min(ans, A[i]);
	}
	printf("%d\n", ans*K);
	return 0;
}
