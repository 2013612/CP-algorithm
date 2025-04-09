#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;

int n, k;
long long ans = -2e18;
vector<vector<int>> a(1, vector<int>(1, 0)), ne(1, vector<int>());
vector<long long> sum(1, 0), con_sum(1, 0);
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int t, y;
		scanf("%d %d", &t, &y);
		if (t == 1) {
			a.push_back(vector<int>(1, y));
			ne.push_back(vector<int>());
			sum.push_back(0);
			con_sum.push_back(0);
		} else {
			a.back().push_back(y);
			sum.back() += y;
			if (y < 0) {
				pq.push({y, a.size() - 1});
			}
		}
	}
	
	con_sum.push_back(0);
	
	for (int i = sum.size() - 1; i >= 0; i--) {
		con_sum[i] = con_sum[i + 1] + sum[i];
	}
	
	int cnt = 0;
	long long ne_sum = 0;
	for (int i = max(0, (int)a.size() - 1 - k); i < a.size(); i++) {
		long long temp = con_sum[i] + a[i][0];
		if (i > 0) {
			for (auto x : ne[i - 1]) {
				ne_sum -= x;
				cnt--;
			}
		}
		while (!pq.empty() && cnt + a.size() - i - 1 < k) {
			auto [val, pos] = pq.top();
			pq.pop();
			if (pos >= i) {
				ne[pos].push_back(val);
				ne_sum += val;
				cnt++;
			}
		}
		
		ans = max(ans, temp - ne_sum);
	}
	printf("%lld\n", ans);
	return 0;
}
