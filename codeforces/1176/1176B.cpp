#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int abs(int x) {
	return x > 0? x: -x;
}

int T, N, ans, a[1004], cou1, cou2;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		ans = 0;
		cou1 = 0;
		cou2 = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			a[j] = a[j] % 3;
			if (a[j] == 0) {
				ans++;
			} else if (a[j] == 1) {
				cou1++;
			} else {
				cou2++;
			}
		}
		printf("%d\n", ans + min(cou1, cou2) + abs(cou1 - cou2)/3);
	}
	
	return 0;
}
