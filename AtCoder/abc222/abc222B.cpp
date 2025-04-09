#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans, P;
int main() {
	scanf("%d %d", &N, &P);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp < P) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
