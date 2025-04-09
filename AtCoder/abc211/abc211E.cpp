#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int N, K;
long long ans, dis[102][102], num[102][102];
string s[20];
vector<int> edge[102];

void f(int first, int i, int j, set<int> k, int num) {
	if (i * N + j < first) {
		return;
	}
	if (num == K) {
		printf("%d %d %d\n", first, i, j);
		ans++;
		return;
	}
	if (!k.count((i - 1) * N + j) && s[i - 1][j] == '.') {
		k.insert((i - 1) * N + j);
		f(first, i - 1, j, k, num + 1);
		k.erase((i - 1) * N + j);
	}
	if (!k.count((i + 1) * N + j) && s[i + 1][j] == '.') {
		k.insert((i + 1) * N + j);
		f(first, i + 1, j, k, num + 1);
		k.erase((i + 1) * N + j);
	}
	if (!k.count(i * N + j - 1) && s[i][j - 1] == '.') {
		k.insert(i * N + j - 1);
		f(first, i, j - 1, k, num + 1);
		k.erase(i * N + j - 1);
	}
	if (!k.count(i * N + j + 1) && s[i][j + 1] == '.') {
		k.insert(i * N + j + 1);
		f(first, i, j + 1, k, num + 1);
		k.erase(i * N + j + 1);
	}
}

int main() {
	scanf("%d %d", &N, &K);
	s[0] = s[N + 1] = "#############";
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
		s[i] = "#" + s[i] + "#";
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			set<int> k;
			if (s[i][j] == '.') {
				f(i * N + j, i, j, k, 1);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
