#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[300006], ans, maxi;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		maxi = max(maxi, a[i]);
	}
	int cou = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != maxi) {
			ans = max(ans, cou);
			cou = 0;
		} else {
			cou++;
		}
	}
	ans = max(ans, cou);
	printf("%d\n", ans);
	return 0;
}
