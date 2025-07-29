#include<iostream>
#include<vector>
#include<algorithm>
#include<atcoder/segtree>
using namespace std;
using namespace atcoder;

typedef pair<int, int> pii;

int n, m, q, ans[200005];
pii a[200005];
pair<pii, int> b[200005];


int f(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

void inside() {
	segtree<int, f, e> seg(2000006);
	
	for (int i = 0; i < m; i++) {
		seg.set(a[i].second, seg.get(a[i].second) + 1);
	}
	
	sort(a, a + m);
	
	sort(b, b + q);
	
	int j = 0;
	for (int i = 0; i < q; i++) {
		while (j < m && a[j].first < b[i].first.first) {
			seg.set(a[j].second, seg.get(a[j].second) - 1);
			j++;
		}
		
		ans[b[i].second] += seg.prod(b[i].first.first, b[i].first.second);
	}
}

void outside() {
	segtree<int, f, e> seg(2000006);
	
	for (int i = 0; i < m; i++) {
		seg.set(a[i].second, seg.get(a[i].second) + 1);
	}
	
	sort(a, a + m);
	
	sort(b, b + q);
	
	int j = m - 1;
	for (int i = q - 1; i >= 0; i--) {
		while (j >= 0 && a[j].first > b[i].first.first) {
			seg.set(a[j].second, seg.get(a[j].second) - 1);
			j--;
		}
		
		ans[b[i].second] += seg.prod(b[i].first.second, 2e6 + 1);
	}
}

void no_inter() {
	for (int i = 0; i < q; i++) {
		int pos = lower_bound(a, a + m, make_pair(b[i].first.second, -1)) - a;
		ans[b[i].second] += m - pos;
	}
	
	vector<int> v;
	for (int i = 0; i < m; i++) {
		v.push_back(a[i].second);
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < q; i++) {
		int pos = lower_bound(v.begin(), v.end(), b[i].first.first) - v.begin();
		ans[b[i].second] += pos;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &b[i].first.first, &b[i].first.second);
		b[i].second = i;
	}
	
	inside();
	outside();
	no_inter();
	
	for (int i = 0; i < q; i++) {
		printf("%d\n", m - ans[i]);
	}
	
	return 0;
}