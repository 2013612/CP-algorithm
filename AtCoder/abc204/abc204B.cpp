#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		ans += max(0, temp - 10);
	}
	printf("%d\n", ans);
	return 0;
}
