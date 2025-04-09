#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, T, ans, a[400006];
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		if (a[0] < a[N - 1]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
} 
