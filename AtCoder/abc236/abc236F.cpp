#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
typedef pair<int, int> pii;

int n;
pii c[100006];
unordered_set<int> us;
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i < (1 << n); i++) {
		int t;
		scanf("%d", &t);
		c[i] = {t, i};
	}
	sort(c + 1, c + (1 << n));
	for (int i = 1; i < (1 << n); i++) {
		if (us.count(c[i].second) == 0) {
			ans = ans + c[i].first;
			unordered_set<int> t;
			for (auto x:us) {
				t.insert(x ^ c[i].second);
			}
			for (auto x:t) {
				us.insert(x);
			}
			us.insert(c[i].second);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
