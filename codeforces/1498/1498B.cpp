#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int T;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N, W;
		scanf("%d %d", &N, &W);
		int a[103];
		for (int j = 0; j < 50; j++) {
			a[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			int w;
			scanf("%d", &w);
			int two = 1;
			for (int k = 0; ; k++) {
				if (w == two) {
					a[k]++;
					break;
				}
				two *= 2;
			}
		}
		int ca = W;
		int ans = 0;
		while (N > 0) {
			ca = W;
			ans++;
			for (int i = 21; i >= 0; ) {
				if (a[i] > 0) {
					if (ca >= (1 << i)) {
						ca -= (1 << i);
						a[i]--;
						N--;
					} else {
						i--;
					}
				} else {
					i--;
				}
			}
			//cout << ca << endl;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
