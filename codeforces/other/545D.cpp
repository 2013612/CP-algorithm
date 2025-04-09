#include<iostream>
#include<algorithm>
using namespace std;

int N, t[100006], ans;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i]);
	}
	sort(t, t + N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum <= t[i]) {
			ans++;
			sum += t[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
