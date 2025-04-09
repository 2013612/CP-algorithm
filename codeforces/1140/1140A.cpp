#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans, a[10005];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		maxi = max(maxi, a[i]);
		if (maxi == i + 1) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
