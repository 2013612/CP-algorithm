#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int, int>> pipii; 

int n, a[200006], b[200006];
pipii edge[400006];
long long sum, ans;
set<int> l, r;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		edge[i] = {a[i], {0, i}};
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		edge[n + i] = {b[i], {i, i % n + 1}};
		sum += b[i];
	}
	sort(edge + 1, edge + 2 * n + 1, greater<pipii>());
	for (int i = 1; i <= 2 * n; i++) {
		int v1 = edge[i].second.first;
		int v2 = edge[i].second.second;
		int dis = edge[i].first;
		if (l.count(v1) == 1) {
			if (l.count(v2) == 0) {
				r.insert(v2);
				ans += dis;
			}
		} else if (r.count(v1) == 1){
			if (r.count(v2) == 0) {
				l.insert(v2);
				ans += dis;
			}
		} else {
			if (l.count(v2) == 1) {
				r.insert(v1);
				ans += dis;
			} else if (r.count(v2) == 1) {
				l.insert(v1);
				ans += dis;
			} else {
				r.insert(v1);
				l.insert(v2);
				ans += dis;
			}
		}
	}
	printf("%lld\n", sum - ans);
	return 0;
}
