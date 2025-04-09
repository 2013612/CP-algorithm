#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans, a[300006], b[300006];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp] = i;
	}
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		int temp2 = a[temp] - i;
		temp2 = (temp2 + N) % N;
		b[temp2]++;
	}
	for (int i = 0; i <= N; i++) {
		ans = max(ans, b[i]);
	}
	printf("%d\n", ans);
	return 0;
}
