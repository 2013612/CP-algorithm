#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

int N, M, Q, X[103];
vector<pair<int, int>> ba;
int main() {
	scanf("%d %d %d", &N, &M, &Q);
	for (int i = 0; i < N; i++) {
		pair<int, int> temp;
		scanf("%d %d", &temp.second, &temp.first);
		ba.push_back(temp);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &X[i]);
	}
	sort(ba.begin(), ba.end(), greater<pair<int, int>>());
	for (int i = 0; i < Q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = 0;
		vector<bool> con(103, false);
		vector<int> av;
		for (int j = 1; j <= M; j++) {
			if (j >= l && j <= r) continue;
			av.push_back(X[j]);
		}
		sort(av.begin(), av.end());
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < av.size(); k++) {
				if (!con[k] && av[k] >= ba[j].second) {
					con[k] = true;
					ans += ba[j].first;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
