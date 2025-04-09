#include<iostream>
#include<utility>
#include<set>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

int N, M, ans;
set<pii> rel;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		pii temp;
		scanf("%d %d", &temp.first, &temp.second);
		rel.insert(temp);
	}
	for (int i = 0; i < (1 << N); i++) {
		vector<int> t;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				t.push_back(j + 1);
			}
		}
		bool can = true;
		for (int j = 0; j < t.size(); j++) {
			for (int k = j + 1; k < t.size(); k++) {
				if (!rel.count({t[j], t[k]})) {
					can = false;
					break;
				}
			}
			if (!can) {
				break;
			}
		}
		if (can) {
			ans = max(ans, (int)t.size());
		}
	}
	printf("%d\n", ans);
	return 0;
}
