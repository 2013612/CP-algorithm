#include<iostream>
using namespace std;

int N, a[300006];
struct node {
	node () {
		lazy = false;
	}
	int mini, L, R;
	node *left, *right;
	bool lazy;
};

struct seg_tree {
	node *root;
	void build (node* now, int l, int r) {
		now -> L = l;
		now -> R = r;
		if (l == r) {
			now -> mini = a[l];
		} else {
			int mid = (l + r)/2;
			now -> left = new node;
			now -> right = new node;
			build (now -> left, l, mid);
			build (now -> right, mid + 1, r);
			now -> mini = min (now -> left -> mini, now -> right -> mini);
		}
	}
	
	int mini (node* now, int l, int r) {
		int mid = (l + r)/2;
		if (l == L && r == R) {
			return now -> mini;
		}
		if (l > mid) {
			return mini (now -> right, l, r);
		} else if (r <= mid) {
			return mini (now -> left, l, r);
		} else {
			return min (mini (now -> left, l, mid), mini (now -> right, mid + 1, r));
		}
	}
	
	void update (node* now, int l, int r, int val) {
		int mid = (l + r)/2;
		lazy = false;
		if (l == L && r == R) {
			now -> mini = val;
			lazy = true;
			return;
		}
		if (l > mid) {
			update (now -> right, l, r, val);
		} else if (r <= mid) {
			update (now -> left, l, r, val);
		} else {
			update (now -> left, l, mid, val);
			update (now -> right, mid + 1, r, val);
		}
		now -> mini = min (now -> left -> mini, now -> right -> mini);
	}
};

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &a[i]);
	}
	return 0;
}
