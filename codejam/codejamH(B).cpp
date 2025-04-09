#include<iostream>
using namespace std;

int T, N;
char c[5000007];
int prefix[5000007];
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		scanf("%s", c);
		prefix[0] = 0;
		for (int j = 1; j <= N; j++) {
			prefix[j] = prefix[j - 1] + (c[j - 1] - '0');
			//printf("%d ", prefix[j]);
		}
		//printf("\n");
		int painted = (N + 1)/2;
		int ans = 0;
		for (int j = painted; j <= N; j++) {
			ans = max(ans, prefix[j] - prefix[j - painted]);
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}
