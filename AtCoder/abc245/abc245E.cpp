#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int> pii;

int n, m, ans;
pii c[200006], b[200006];
map<int, int> l;
bool can = true;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i].first);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i].second);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i].first);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i].second);
	}
	sort(c, c + n, greater<pii>());
	sort(b, b + m, greater<pii>());
	
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (c[i].first <= b[j].first) {
			l[b[j].second]++;
			j++;
		}
		map<int, int>::iterator it = l.lower_bound(c[i].second);
		if (it == l.end()) {
			can = false;
			break;
		} else {
			(it->second)--;
			if (it->second == 0) {
				l.erase(it);
			}
		}
	}
	if (can) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
