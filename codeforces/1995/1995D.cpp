#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, a[200006], ans, k, c;
vector<int> v[26], bit[20];
string s;
deque<pair<int, int>> q;
int maxPos[300006];

void solve() {
	scanf("%d %d %d", &n, &c, &k);
	
	cin >> s;
	
	q.clear();
	for (int i = 0; i < c; i++) {
		v[i].clear();
	}
	for (int i = 0; i < (1 << c); i++) {
		maxPos[i] = -1;
		int temp = i;
		int cnt = 0;
		while (temp > 0) {
			if (temp & 1) {
				cnt++;
			}
			temp >>= 1;
		}
		bit[cnt].push_back(i);
	}
	
	for (int i = 0; i < n; i++) {
		v[s[i] - 'A'].push_back(i);
	}
	
	int temp = 0;
	
	for (int i = k - 1; i >= 0; i--) {
		int u = s[i] - 'A';
		if ((temp & (1 << u)) == 0) {
			q.push_back({i, 1 << u});
			maxPos[1 << u] = i;
		}
		
		if (temp == (1 << c) - 1) {
			break;
		}
	}
	
	for (int u = 1; u <= c; u++) {
		for (int j: bit[u]) {
//			printf("!%d %d\n", k, j);
			while (true) {
				int pos = maxPos[j];
				if (pos == -1) {
					break;
				}
				for (int i = 0; i < c; i++) {
//					printf("$ %d %d %d\n", i, pos, v[i].size());
					if (v[i].empty()) {
						continue;
					}
					int t = upper_bound(v[i].begin(), v[i].end(), pos + k) - v[i].begin() - 1;
//					printf("@ %d %d %d %d\n", j, pos, i, t);
					if (t < 0 || v[i][t] <= pos || v[i][t] > pos + k) {
						continue;
					}
					int newCheck = j | (1 << i);
					
					if (v[i][t] > maxPos[newCheck]) {
						maxPos[newCheck] = v[i][t];
					}
				}
				
				if (maxPos[j] == n - 1) {
					printf("%d\n", u);
					return;
				}
				
				if (maxPos[j] == pos) {
					break;
				}
			}
			
		}
	}
	
	printf("1\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	
	return 0;
}