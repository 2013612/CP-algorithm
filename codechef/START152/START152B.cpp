#include <bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int n, q;

struct Node {
	int sum[3] = {0, 0, 0};
	
	Node() {
		
	}
	
	Node(int one, int two, int three) {
		sum[0] = one;
		sum[1] = two;
		sum[2] = three;
	}
};

vector<Node> v;

Node op(Node a, Node b) {
	return Node(a.sum[0] + b.sum[0], a.sum[1] + b.sum[1], a.sum[2] + b.sum[2]);
}

Node e() {
  return Node(0, 0, 0);
}

void solve() {
    scanf("%d %d", &n, &q);
    v.resize(n);
    
    for (int i = 0; i < n; i++) {
    	int t;
    	scanf("%d", &t);
    	v[i] = e();
    	v[i].sum[t - 1]++;
	}
	
	segtree<Node, op, e> seg(v);
	
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		
		if ((r - l) & 1) {
			printf("No\n");
			continue;
		}
		
		Node temp = seg.prod(l, r);
		int maxi = max({temp.sum[0], temp.sum[1], temp.sum[2]});
		if (maxi == (r - l) / 2) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
	    solve();
	}
	
	return 0;
}
