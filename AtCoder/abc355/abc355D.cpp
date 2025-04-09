#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int n;
pair<int, int> a[500005];
pair<int, pair<int, int>> events[1000006];
long long ans;
set<int> s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
		events[2 * i] = {a[i].first, {0, i}};
		events[2 * i + 1] = {a[i].second, {1, i}};
	}
	sort(events, events + 2 * n);
	
	for (int i = 0; i < 2 * n; i++) {
		if (!events[i].second.first) {
			ans += s.size();
			s.insert(events[i].second.second);
		} else {
			s.erase(events[i].second.second);
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}