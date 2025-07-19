#include<bits/stdc++.h>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

typedef pair<pair<int, int>, pair<pair<int, int>, pair<int, int>>> T;

int n, q;
string s;

T op(T a, T b) {
	int maxi = max(a.first.first, b.first.first);
	
	if (a.second.second.first == b.second.first.first) {
		maxi = max(maxi, a.second.second.second + b.second.first.second);
	}
	
	if (a.first.second == a.second.first.second) {
		if (a.second.first.first == b.second.first.first) {
			a.second.first.second += b.second.first.second;
		}
	}
	
	if (b.first.second == b.second.second.second) {
		if (a.second.second.first == b.second.second.first) {
			b.second.second.second += a.second.second.second;
		}
	}
	
	return {{maxi, a.first.second + b.first.second}, {a.second.first, b.second.second}};
}

T e() {
	return {{0, 0}, {{-1, 0}, {-1, 0}}};
}

int main() {
	scanf("%d %d", &n, &q);
	cin >> s;
	
	segtree<T, op, e> seg(n);
	
	for (int i = 0; i < n; i++) {
		seg.set(i, {{1, 1}, {{s[i] - 'a', 1}, {s[i] - 'a', 1}}});
	}
	
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		
		if (t == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			pos--;
			seg.set(pos, {{1, 1}, {{c - 'a', 1}, {c - 'a', 1}}});
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			l--;
			
			T temp = seg.prod(l, r);
			
			printf("%d\n", temp.first.first);
		}
		
//		for (int i = 0; i < n; i++) {
//			T temp = seg.get(i);
//			
//			printf("%d %d\n", temp.second.first.first, temp.first);
//		}
	}
	
	return 0;
}