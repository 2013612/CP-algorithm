#include<iostream>
#include<unordered_map>
using namespace std;

int K, N, ans, a[300006];
unordered_map<int, int> color;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < K - 1; i++) {
		color[a[i]]++;
	}
	for (int i = K - 1; i < N; i++) {
		color[a[i]]++;
		int size = color.size();
		ans = max(ans, size);
		color[a[i - (K - 1)]]--;
		if (color[a[i - (K - 1)]] == 0) {
			color.erase(a[i - (K - 1)]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
