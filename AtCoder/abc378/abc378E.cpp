#include<iostream>
#include<algorithm>
#include<vector>
#include<atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int n, m, a[200006], pre[200006];
vector<int> v;
long long ans, sum;
fenwick_tree<int> fw(200006);

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pre[i + 1] = (pre[i] + a[i]) % m;
		v.push_back(pre[i + 1]);
	}
	sort(v.begin(), v.end());
	
	
	for (int i = 1; i <= n; i++) {
		ans += 1ll * i * pre[i];
		int ind = lower_bound(v.begin(), v.end(), pre[i]) - v.begin();
		int ext = fw.sum(ind + 1, n + 1);
		ans += 1ll * ext * m;
		fw.add(ind, 1);
		
		ans -= sum;
		sum += pre[i];
	}
	
	printf("%lld\n", ans);
	
	return 0;
}