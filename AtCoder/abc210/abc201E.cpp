#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<long long, long long> pll;

long long gcd(long long a, long long b) {
	return b == 0? a : gcd(b, a % b);
}

long long N, M, ans;
vector<pll> edge;
int main() {
	scanf("%lld %lld", &N, &M);
	long long g = 0;
	for (int i = 0; i < M; i++) {
		pll temp;
		scanf("%lld %lld", &temp.second, &temp.first);
		edge.push_back(temp);
		g = gcd(g, temp.second);
	}
	g = gcd(g, N);
	if (g != 1) {
		printf("-1\n");
		return 0;
	}
	sort(edge.begin(), edge.end());
	long long node = N;
	for (int i = 0; i < M; i++) {
		long long temp = gcd(node, edge[i].second);
		if (temp == node) {
			continue;
		}
		ans += edge[i].first * (node - temp);
		node = temp;
	}
	printf("%lld\n", ans);
	return 0;
}
