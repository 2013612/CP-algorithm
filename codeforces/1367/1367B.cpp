#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T, N, ans, a[100006];
int main() {
	scanf("%d", &T);
	for (int j = 0; j < T; j++) {
		scanf("%d", &N);
		int sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			a[i] = a[i] % 2;
			sum += a[i];
		}
		if (sum != N/2) {
			ans = -1;
		} else {
			int temp = 0;
			for (int i = 0; i < N; i++) {
				if (a[i] != (i % 2)) {
					//cout << i << endl;
					temp++;
				}
			}
			ans = temp/2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
