#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[1004], ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int count = 1;
	int maxi = 0;
	for (int i = 1; i < N; i++) {
		if (a[i] == a[i - 1] + 1) {
			count++;
		} else {
			if (count >= 3) {
				maxi = max(maxi, count);
			}
			count = 1;
		}
	}
	maxi = max(maxi, count);
	if (maxi >= 3) {
		ans += maxi - 2;
	}
	if (a[0] == 1) {
		for (int i = 1; i < maxi; i++) {
			if (a[i] != a[i - 1] + 1) {
				break;
			}
			if (i == maxi - 1) {
				ans++;
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	if (a[N - 1] == 1000) {
		for (int i = N - 1; i > N - maxi; i--) {
			if (a[i] != a[i - 1] + 1) {
				break;
			}
			if (i == N - maxi + 1) {
				ans++;
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	printf("%d\n", ans);
	return 0;
}
