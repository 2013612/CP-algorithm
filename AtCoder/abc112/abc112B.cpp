#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, T, c[1004], t[1004], ans;
int main(){
	scanf("%d %d", &N, &T);
	ans = 1e9;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c[i], &t[i]);
		if (t[i] <= T) {
			ans = min(ans, c[i]);
		}
	}
	if (ans > 100000) {
		printf("TLE\n");
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}
