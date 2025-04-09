#include<iostream>
using namespace std;

int T, N, M;
long long C[1000007], ans[1000007];

int main() {
	freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
	freopen("running_on_fumes_chapter_1_output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &N, &M);
		bool success = true;
		for (int j = 0; j < N; j++) {
			scanf("%lld", &C[j]);
		}
		for (int j = 0; j <= M; j++) {
			ans[j] = 0;
		}
		for (int j = M + 1; j < N; j++) {
			long long mini = -1;
			for (int k = j - M; k < j; k++) {
				if (C[k] != 0) {
					if (mini == -1) {
						mini = ans[k] + C[k];
					} else {
						mini = min(mini, ans[k] + C[k]);
					}
					
				}
			}
			if (mini == -1) {
				success = false;
				break;
			} else {
				ans[j] = mini;
			}
		}
		
		printf("Case #%d: ", i);
		if (!success) {
			printf("-1\n");
		} else {
			printf("%lld\n", ans[N - 1]);
		}
	}
}
