#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, a[200006], ans[200006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		printf("0 ");
		ans[0] = 0;
		for (int j = 1; j < N; j++) {
			if ((a[j] & a[j - 1]) != a[j - 1]) {
				long long ans = 0;
				for (int k = 0; k <= 31; k++) {
					long long temp = (1ll << k);
					if ((a[j - 1] & temp) && !(a[j] & temp)) {
						ans += temp;
					}
				}
				printf("%d ", ans);
				a[j] = a[j] ^ ans;
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	return 0;
}
