#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
bool visited[200005];
vector<int> v[200005];

int dfs(int cur) {
	int sum = 1;
	visited[cur] = true;
	
	vector<int> p;
	
	for (auto x: v[cur]) {
		if (!visited[x]) {
			p.push_back(dfs(x));
		}
	}
	
	sort(p.begin(), p.end(), greater<int>());
	
	if (p.size() >= 3) {
		sum += p[0] + p[1] + p[2];
	}
	
	if (p.size() >= 4) {
		ans = max(ans, sum + p[3]);
	} else if (p.size()) {
		ans = max(ans, 1 + p[0]);
	}
	
	return sum;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1);
	
	if (ans < 5) {
		ans = -1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}