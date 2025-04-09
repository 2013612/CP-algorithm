#include<iostream>
#include<utility>
#include<vector>
using namespace std;

const int M = 1000000007;
long long T, N, K, W, A, B, C, D, ans;
pair<long long, long long> dim[1000007];
int main() {
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		ans = 1;
		scanf("%lld %lld %lld", &N, &K, &W);
		for (int j = 0; j < K; j++) {
			scanf("%lld", &dim[j].first);
		}
		scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
		for (int j = K; j < N; j++) {
			dim[j].first = A * dim[j - 2].first + B * dim[j - 1].first + C;
			dim[j].first = dim[j].first % D + 1;
		}
		for (int j = 0; j < K; j++) {
			scanf("%lld", &dim[j].second);
		}
		scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
		for (int j = K; j < N; j++) {
			dim[j].second = A * dim[j - 2].second + B * dim[j - 1].second + C;
			dim[j].second = dim[j].second % D + 1;
		}
		for (int j = 0; j < N; j++) {
			printf("L%d: %lld, H%d: %lld\n", j, dim[j].first, j, dim[j].second);
		}
		/*long long left = dim[0].first;
		long long height = dim[0].second;
		long long per = 0;
		for (int j = 0; j < N; j++) {
			height = max(height, dim[j].second);
			long long P = (dim[j].first + W - left + height) * 2 % M;
			ans = ans * (per + P) % M;
			printf("P%d : %lld, ans%d : %lld\n", j, P + per, j, ans);
			if (dim[j + 1].first > dim[j].first + W) {
				left = dim[j + 1].first;
				height = dim[j + 1].second;
				per += P;
			}
		}*/
		
		long long height = dim[0].second;
		long long per = 0;
		for (int j = 0; j < N; j++) {
			if (j == 0 || dim[j].first > dim[j - 1].first + W) {
				per += (W + dim[j].second) * 2 % M;
				height = dim[j].second;
			} else {
				per += (dim[j].first - dim[j - 1].first) * 2;
				per += max((long long)0, dim[j].second - height) * 2;
				height = max(height, dim[j].second);
			}
			per = per % M;
			ans = ans * per;
			ans = ans % M;
		}
		ans = (ans + M) % M;
		printf("Case #%lld: %lld\n", i, ans);
	}
}
