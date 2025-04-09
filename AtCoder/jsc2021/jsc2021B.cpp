#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, a[10005];
vector<int> ans;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N + M; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N + M + 1);
	for (int i = 1; i <= N + M; i++) {
		if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	return 0;
}
