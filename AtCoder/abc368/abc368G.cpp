#include<iostream>
#include<set>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

int n, b[100006], q;
vector<long long> a;
set<int> b_ind;

long long op(long long a, long long b) {
	return a + b;
}

long long e() {
	return 0;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a.push_back(t);
	}
	
	segtree<long long, op, e> seg(a);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (b[i] > 1) {
			b_ind.insert(i);
		}
	}
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		u--;
		if (t == 1) {
			seg.set(u, v);
		} else if (t == 2) {
			b[u] = v;
			if (v == 1) {
				b_ind.erase(u);
			} else {
				b_ind.insert(u);
			}
		} else {
			v--;
			auto it = b_ind.lower_bound(u);
			long long ans = 0;
			int start = u;
			while (start < v + 1) {
				int pos;
				if (it == b_ind.end()) {
					pos = 1e9;
				} else {
					pos = *it;
				}
				
				if (start == pos) {
					ans = max(ans + seg.get(start), ans * b[start]);
					start++;
					it++;
//					printf("!%d %d\n", start, pos);
				} else {
					int last = min(v + 1, pos);
//					printf("!%d %d\n", start, last);
					ans += seg.prod(start, last);
					start = last;
				}
			}
			printf("%lld\n", ans);
		}
	}
	
	
	return 0;
}
