#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, a[200006], prev[200006];
vector<vector<pair<int, int>>> lis;
bool success;

bool f(vector<pair<int, int>> a, int b) {
	return a.back().first < b;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		int pos = lower_bound(lis.begin(), lis.end(), a[i], f) - lis.begin();
		if (pos == lis.size()) {
			lis.push_back(vector<pair<int, int>>());
		}
		
		int k = lis[pos].size();
		if (k >= 2) {
			if (lis[pos][k - 2].first == a[i]) {
				if (pos == 0 || lis[pos - 1].back().second < lis[pos][k - 2].second) {
					continue;
				}
			}
		}
		lis[pos].push_back({a[i], i});
	}
	
	int start = 0;
	int end = 1;
	for (int i = lis.size() - 1; i >= 0 && !success; i--) {
		if (i == lis.size() - 1 && lis[i].size() > 1) {
//			printf("! %d\n", i);
			success = true;
		} else if (i == lis.size() - 1 && lis[i][0].second + 1 < n) {
			success = true;
		} else if (i == 0) {
//			printf("@ %d %d\n", i, end);
			if (lis[0][end - 1].second > 0) {
				
				success = true;
			}
		} else {
			int k = 0;
			
			while (k < lis[i - 1].size() && (lis[i - 1][k].first >= lis[i][start].first || lis[i - 1][k].second > lis[i][start].second)) {
				k++;
			}
			
			int k2 = k;
			int k3;
			
			for (int j = start; j < end; j++) {
				while (k < lis[i - 1].size() && (lis[i - 1][k].first >= lis[i][j].first || lis[i - 1][k].second > lis[i][j].second)) {
					k++;
				}
				int l = k;
				while (l < lis[i - 1].size() && lis[i - 1][l].first < lis[i][j].first && lis[i - 1][l].second <= lis[i][j].second) {
					if (lis[i - 1][l].first + 1 < lis[i][j].first && lis[i - 1][l].second + 1 < lis[i][j].second) {
//						printf("# %d\n", i);
						success = true;
						break;
					}
					l++;
				}
				k3 = l;
			}
			
			start = k2;
			end = k3;
		}
	}
	
	printf("%d\n", lis.size() + success);
	
	return 0;
}