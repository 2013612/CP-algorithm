#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int q;
map<int, int> m;
int main() {
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x;
			scanf("%d", &x);
			m[x]++;
		} else if (t == 2) {
			int x, c;
			scanf("%d %d", &x, &c);
			m[x] -= c;
			if (m[x] <= 0) {
				m.erase(x);
			}
		} else {
			printf("%d\n", m.rbegin()->first - m.begin()->first);
		}
	}
	return 0;
}