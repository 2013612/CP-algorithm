#include<iostream>
#include<unordered_map>
using namespace std;

const int M = 2e5;

int n, l, a[200006], ans[200006];
unordered_map<int, unordered_map<int, int>> um;

void find(int cur_val, int cur_cnt, int last_cnt, int sum, int max) {
	if (sum > M) {
		return;
	}
	
	ans[sum] = min(ans[sum], max);
	
	int cnt = um[sum][cur_val];
	
	if (cnt >= cur_cnt) {
		return;
	}
	
	um[sum][cur_val] = cur_cnt;
	
	
	if (cur_cnt < last_cnt) {
		find(cur_val, cur_cnt + 1, last_cnt, sum + cur_val, max);
	}
	
	if (cur_val - 2 > 0) {
		find(cur_val - 2, 1, cur_cnt, sum + cur_val - 2, max);
	}
}
	
	
void solve() {
	for (int i = 1; i <= M; i++) {
		ans[i] = 1e9;
	}
	
	for (int i = 1; i * (l - 1) <= M ; i++) {
		find(l - 1, i, i, i * (l - 1), i);
	}
}

int main() {
	scanf("%d %d", &n, &l);
	solve();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		printf("%d\n", ans[a[i]] < 1e8 ? ans[a[i]] : -1);
	}
	
	return 0;
}