#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

long long T, N, K, a[1004], ans, b[1004][70];
int main(){
	scanf("%lld", &T);
	for (int i = 0; i < T; i++) {
		scanf("%lld %lld", &N, &K);
		for (int j = 0; j < N; j++) {
			scanf("%lld", &a[j]);
		}
		bool Fail = false;
		for (int j = 0; j < 200; j++) {
			for (int k = 0; k < 70; k++) {
				b[j][k] = 0;
			}
		}
		long long index = 0;
		for (int j = 0; j < N; j++) {
			long long temp = a[j];
			long long t = 0;
			while (temp > 0) {
				b[j][t] = temp % K;
				if (b[j][t] > 1) {
					Fail = true;
				}
				temp /= K;
				t++;
			}
			index = max(index, t);
		}
		if (Fail) {
			printf("NO\n");
			continue;
		}
		for (int j = 0; j < index; j++) {
			bool exist = false;
			for (int k = 0; k < N; k++) {
				if (b[k][j] == 1) {
					if (!exist) {
						exist = true;
					} else {
						Fail = true;
					}
				}
			}
		}
		if (Fail) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
