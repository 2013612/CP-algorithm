#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, K, a[200006][2];
long long b[103];
int main(){
	scanf("%d %d", &N, &K);
	b[0] = 1;
	for (int i = 1; i < 20; i++) {
		b[i] = b[i - 1]*10;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i][0]);
		for (int j = 12; j >= 0; j--) {
			if (a[i][0]/b[j] != 0) {
				a[i][1] = j + 1;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j && (1ll*a[i][0]*b[a[j][1]] + 1ll*a[j][0]) % K == 0) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
