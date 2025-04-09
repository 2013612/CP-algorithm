#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, N, ans, a[200006];
vector<int> b; 
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		b.clear();
		b.push_back(a[0]);
		for (int j = 1; j < N - 1; j++) {
			if ((a[j - 1] < a[j] && a[j] > a[j + 1]) || (a[j - 1] > a[j] && a[j] < a[j + 1])) {
				b.push_back(a[j]);
			}
		}
		b.push_back(a[N - 1]);
		printf("%d\n", b.size());
		for (auto x:b) {
			printf("%d ", x);
		}
		printf("\n");
	}
	return 0;
}
