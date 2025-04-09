#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int T, N, M;
long long ans_w, ans_b;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		ans_w = 1ll*N*M / 2;
		ans_b = ans_w;
		if (N % 2 && M % 2) {
			ans_w += 1;
		}
		int a[4], b[4];
		scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
		scanf("%d %d %d %d", &b[0], &b[1], &b[2], &b[3]);
		long long temp;
		temp = 1ll * (a[3] - a[1] + 1) * (a[2] - a[0] + 1) / 2;
		if ((a[0] + a[1]) % 2) {
			if ((a[3] - a[1] + 1) % 2 && (a[2] - a[0] + 1) % 2) {
				temp++;
			}
		}
		//cout << "!" << temp << endl;
		ans_w += temp;
		ans_b -= temp;
		long long temp2;
		int c[4];
		c[0] = max(a[0], b[0]);
		c[1] = max(a[1], b[1]);
		c[2] = min(a[2], b[2]);
		c[3] = min(a[3], b[3]);
		temp2 = 1ll * (c[3] - c[1] + 1) * (c[2] - c[0] + 1);
		long long temp3;
		temp3 = 1ll * (b[3] - b[1] + 1) * (b[2] - b[0] + 1) / 2;
		if ((b[0] + b[1]) % 2 == 0) {
			if ((b[3] - b[1] + 1) % 2 && (b[2] - b[0] + 1) % 2) {
				temp3++;
			}
		}
		//cout << "@" << temp2 << endl;
		//cout << "#" << temp3 << endl;
		if ((c[0] + c[1]) % 2) {
			if ((c[3] - c[1] + 1) % 2 && (c[2] - c[0] + 1) % 2) {
				temp2++;
			}
		}
		temp3 += (temp2) / 2;
		ans_w -= temp3;
		ans_b += temp3;
		printf("%lld %lld\n", ans_w, ans_b);
	}
	return 0;
}
