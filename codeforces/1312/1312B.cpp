#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int T, N, a[1001], ans;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		sort(a, a + N, greater<int>());
		for (int j = 0; j < N; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	return 0;
}
