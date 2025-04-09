#include<iostream>
#include<vector>
using namespace std;

int n, m, s = 1, a[1100006], ans[1100006];

vector<int> solve(int c, int size) {
	if (size == 1) {
		ans[0] ^= a[s - c - 1];
		vector<int> v(1, a[s - c - 1]);
		return v;
	}
	int half = size >> 1;
	vector<int> v1 = solve(c, half);
	vector<int> v2 = solve(c + half, half);
	for (int i = 0; i < half; i++) {
		ans[half + i] ^= v1[i];
		v1.push_back(v1[i]);
		v1[i] ^= v2[i];
	}
	
	return v1;
}

int main() {
	scanf("%d %d", &n, &m);
	while (s < n || s < m) {
		s *= 2;
	}
	for (int i = s - n; i < s; i++) {
		scanf("%d", &a[i]);
	}
	solve(0, s);
	for (int i = 0; i < m; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
