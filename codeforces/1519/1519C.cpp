#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int T, N, a[200006], s[200006];

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		long long ans[N + 10];
		unordered_map<int, vector<long long>> team;
		for (int j = 0; j <= N; j++) {
			ans[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}
		for (int j = 0; j < N; j++) {
			scanf("%d", &s[j]);
		}
		for (int j = 0; j < N; j++) {
			if (team.count(a[j]) == 1) {
				team[a[j]].push_back(s[j]);
			} else {
				team[a[j]] = vector<long long>(1, s[j]);
			}
		}
		for (auto x:team) {
			sort(x.second.begin(), x.second.end(), greater<long long>());
			int size = x.second.size();
			long long pre[size + 10];
			pre[0] = 0;
			for (int j = 0; j < size; j++) {
				pre[j + 1] = pre[j] + x.second[j];
			}
			for (int j = 1; j <= size; j++) {
				int ind = size / j * j;
				ans[j] += pre[ind];
			}
		}
		for (int j = 1; j <= N; j++) {
			printf("%lld ", ans[j]);
		}
		printf("\n");
	}
	return 0;
}
