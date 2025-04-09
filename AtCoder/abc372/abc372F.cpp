#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 998244353;

int n, m, k;
vector<int> edges[200005], v, v2;
unordered_map<int, int> um[200005], t;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		edges[x].push_back(y);
		v.push_back(x);
		v2.push_back(x);
		v2.push_back(y);
	}
	
	if (m == 0) {
		printf("1\n");
		return 0;
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	
	t[1] = 0;
	
	for (int x: v2) {
		int ind = lower_bound(v.begin(), v.end(), x) - v.begin();
		ind %= v.size();
		t[x] = ind;
//		printf("%d %d\n", x, ind);
	}
//	printf("\n");
	
	um[0][1] = 1;
	
	for (int i = 0; i < k; i++) {
		for (auto x: um[i]) {
			int ind = t[x.first];
			
//			printf("! %d %d %d\n", i, x.first, ind);
			
			if (v[ind] == x.first) {
				for (auto y: edges[x.first]) {
					int next_ind = t[y];
					int step = 1 + (v[next_ind] + n - y) % n;
					
//					printf("# %d %d %d\n", y, next_ind, step);
//					if (step == 0) {
//						step = n;
//					}
					
					if (i + step > k) {
						step = k - i;
					}
					
					um[i + step][v[next_ind]] = (um[i + step][v[next_ind]] + x.second) % M;
				}
				ind = (ind + 1) % v.size();
			}
			
			int step = (v[ind] + n - x.first) % n;
			
			if (step == 0) {
				step = n;
			}
			
			if (i + step > k) {
				step = k - i;
			}
			um[i + step][v[ind]] = (um[i + step][v[ind]] + x.second) % M;
		}
	}
	
	int ans = 0;
	for (auto x: um[k]) {
		ans = (ans + x.second) % M;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
