#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, a[200006];
vector<int> v[30];
long long ans;
unordered_map<int, pair<long long, int>> um[30];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		int two = 2;
		for (int j = 0; j < 25; j++) {
			if (a[i] % two) {
				v[j].push_back(a[i] / (two / 2));
				break;
			}
			two *= 2;
		}
	}
	
	long long cnt = 0;
	int t = n;
	for (int i = 0; i < 25; i++) {
		int m = v[i].size();
		t -= m;
		
		for (int j = 0; j < 25; j++) {
			um[j].clear();
		}
		
		long long sum = 0;
		for (int j = 0; j < m; j++) {
			ans += (cnt + t) * v[i][j];
			sum += v[i][j];
			for (int k = 1; k < 25; k++) {
				int u = 1 << k;
				um[k][v[i][j] % u].first += v[i][j] / u;
				um[k][v[i][j] % u].second++;
 			}
		}
		
		for (int j = 0; j < m; j++) {
			pair<long long, int> p = {0, 0};
			for (int k = 24; k >= 1; k--) {
				int u = 1 << k;
				sum -= p.first + 1ll * p.second * (1 + v[i][j] / u);
				auto r = um[k][u - v[i][j] % u];
				sum += r.first + 1ll * r.second * (1 + v[i][j] / u);
				
				p = {r.first * 2, r.second};
				if (u - v[i][j] % u >= (1 << (k - 1))) {
					p.first += p.second;
				}
 			}
		}
		
		ans += sum / 2;
		
		cnt += m;
		cnt *= 2;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}