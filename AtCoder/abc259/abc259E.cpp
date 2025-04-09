#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> pii;

int n, ans;
vector<pii> v[200006];
map<pii, int> cnt;
map<int, int> q;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int p, e;
			scanf("%d %d", &p, &e);
			pii temp = {p, e};
			v[i].push_back(temp);
			cnt[temp]++;
			q[p] = max(q[p], e);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (auto x : v[i]) {
			if (q[x.first] == x.second && cnt[x] == 1) {
				ans++;
				break;
			}
		}
	}
	
	printf("%d\n", min(ans + 1, n));
	return 0;
}