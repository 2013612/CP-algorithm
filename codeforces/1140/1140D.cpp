#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N;
long long ans;
int main(){
	scanf("%d", &N);
	for (int i = 2; i < N; i++) {
		ans = ans + 1ll*i*(i + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
