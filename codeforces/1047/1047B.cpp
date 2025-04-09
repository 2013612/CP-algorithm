#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a, b, ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		ans = max(ans, a + b);
	}
	printf("%d\n", ans);
	return 0;
}
