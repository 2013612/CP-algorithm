#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[300006], odd[300006], even[300006], ans;
int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		if (i == 1) {
			odd[1] = a[i];
			odd[300000] = odd[i];
		} else if (i == 2) {
			even[2] = a[i];
			even[300000] = even[i];
		} else if (i % 2 == 0) {
			even[i] = even[i - 2] + a[i];
			even[300000] = even[i];
		} else {
			odd[i] = odd[i - 2] + a[i];
			odd[300000] = odd[i];
		}
	}
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	if (odd[300000] - a[1] == even[300000]) {
		ans++;
	}
	if (a[1] + even[300000] - a[2] == odd[300000] - a[1]) {
		ans++;
	}
	for (int i = 3; i <= N; i++) {
		if (i % 2 == 0) {
			if (odd[i - 1] + even[300000] - even[i] == even[i - 2] + odd[300000] - odd[i - 1]) {
				ans++;
			}
		} else {
			if (odd[i - 2] + even[300000] - even[i - 1] == even[i - 1] + odd[300000] - odd[i]) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
