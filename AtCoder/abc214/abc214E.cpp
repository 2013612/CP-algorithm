#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int> pii;

int T;
pii a[200006];

bool f(pii x, pii y) {
	if (x.second != y.second) {
		return x.second < y.second;
	} else {
		return x.first < y.first;
	}
}

int main() {
	scanf("%d", &T);
	while (T-- > 0) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &a[i].first, &a[i].second);
		}
		sort(a, a + N, f);
		set<pii> have;
		have.insert({1, 1e9});
		bool can = true;
		for (int i = 0; i < N; i++) {
			auto temp = have.lower_bound(a[i]);
			if (temp == have.begin()) {
				if (a[i].second >= (*temp).first) {
					pii t = *temp;
					t.first++;
					have.erase(temp);
					if (t.second >= t.first) {
						have.insert(t);
					}
					continue;
				} else {
					can = false;
					break;
				}
			}
			temp--;
			if ((*temp).second >= a[i].first) {
				pii t = *temp;
				pii t1 = {t.first, a[i].first - 1};
				pii t2 = {a[i].first + 1, t.second};
				have.erase(temp);
				if (t1.second >= t1.first) {
					have.insert(t1);
				}
				if (t2.second >= t2.first) {
					have.insert(t2);
				}
				continue;
			}
			temp++;
			if (temp != have.end()) {
				if (a[i].second >= (*temp).first) {
					pii t = *temp;
					t.first++;
					have.erase(temp);
					if (t.second >= t.first) {
						have.insert(t);
					}
					continue;
				}
			}
			can = false;
			break;
		}
		if (can) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}
