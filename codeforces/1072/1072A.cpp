#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int W, H, K, ans;
int main(){
	scanf("%d %d %d", &W, &H, &K);
	for (int i = 0; i < K; i++) {
		ans += 2 * (W + H) - 4;
		W = W - 4;
		H = H - 4;
	}
	printf("%d\n", ans);
	return 0;
}
