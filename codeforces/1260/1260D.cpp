#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

int N, M, K, T, ans, a[200006], l[200006], r[200006], d[200006];

bool success(int x) {
	int temp = 1e9;
	int temp2 = 0;
	for (int i = 0; i < K; i++) {
		if (d[i] > a[x]) {
			temp = min(temp, l[i]);
			temp2 = max(temp, r[i]);
		}
	}
	int time = N + 1 + temp2 * 2 - temp;
	if (time <= T && time > 0) {
		return true;
	} else {
		return false;
	}
}

int main() {
	scanf("%d %d %d %d", &M, &N, &K, &T);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &l[i], &r[i], &d[i]);
	}
	sort(a, a + M);
	int l = 0;
	int r = M - 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (success(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if (success(l)) {
		ans = l;
	} else {
		ans = r;
	}
	printf("%d\n", M - ans);
	return 0;
} 
