#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, K, a[300006], A, B;
long long ans;
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	A = M / (K + 1);
	B = M % (K + 1);
	ans = 1ll*A*a[N - 1]*K + 1ll*A*a[N - 2] + 1ll*B*a[N - 1]; 
	printf("%lld\n", ans);
	return 0;
}
