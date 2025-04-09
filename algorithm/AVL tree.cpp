#include<iostream>
using namespace std;

struct node {
	node (int x, node* y) {
		val = x;
		parent = y;
		l_size = r_size = 0;
		l_child = r_child = 0;
	}
	int val, l_size, r_size;
	node* l_child, *r_child, *parent;
};

node* root;

int size(node* y) {
	if (y == 0) {
		return -1;
	} else {
		return max(y -> l_size, y -> r_size);
	}
}

void balance_ll (node* y) {
	node* par = y -> parent;
	node* left = y -> l_child;
	if (par == root) {
		par -> r_child = left;
		par -> l_child = left;
	} else {
		if (y -> val > par -> val) {
			par -> r_child = left;
		} else {
			par -> l_child = left;
		}
	}
	y -> l_child = left -> r_child;
	left -> r_child = y;
	left -> parent = par;
	y -> parent = left;
	if (y -> l_child != 0) {
		y -> l_child -> parent = y;
	}
	y -> l_size = size(y -> l_child) + 1;
	left -> r_size = size(y) + 1;
}

void balance_rr (node* y) {
	node* par = y -> parent;
	node* right = y -> r_child;
	if (par == root) {
		par -> r_child = right;
		par -> l_child = right;
	} else {
		if (y -> val > par -> val) {
			par -> r_child = right;
		} else {
			par -> l_child = right;
		}
	}
	y -> r_child = right -> l_child;
	right -> l_child = y;
	right -> parent = par;
	y -> parent = right;
	if (y -> r_child != 0) {
		y -> r_child -> parent = y;
	}
	y -> r_size = size(y -> r_child) + 1;
	right -> l_size = size(y) + 1;
}

void balance_lr (node* y) {
	node* par = y -> parent;
	node* left = y -> l_child;
	node* l_right = left -> r_child;
	if (par == root) {
		par -> r_child = l_right;
		par -> l_child = l_right;
	} else {
		if (y -> val > par -> val) {
			par -> r_child = l_right;
		} else {
			par -> l_child = l_right;
		}
	}
	left -> r_child = l_right -> l_child;
	if (left -> r_child != 0) {
		left -> r_child -> parent = left;
	}
	
	y -> l_child = l_right -> r_child;
	if (y -> l_child != 0) {
		y -> l_child -> parent = y;
	}
	
	l_right -> l_child = left;
	l_right -> r_child = y;
	l_right -> parent = par;
	left -> parent = y -> parent = l_right;
	left -> r_size = size(left -> r_child) + 1;
	y -> l_size = size(y -> l_child) + 1;
	l_right -> l_size = size(left) + 1;
	l_right -> r_size = size(y) + 1;
}

void balance_rl (node* y) {
	node* par = y -> parent;
	node* right = y -> r_child;
	node* r_left = right -> l_child;
	if (par == root) {
		par -> r_child = r_left;
		par -> l_child = r_left;
	} else {
		if (y -> val > par -> val) {
			par -> r_child = r_left;
		} else {
			par -> l_child = r_left;
		}
	}
	right -> l_child = r_left -> r_child;
	if (right -> l_child != 0) {
		right -> l_child -> parent = right;
	}
	y -> r_child = r_left -> l_child;
	if (y -> r_child != 0) {
		y -> r_child -> parent = y;
	}
	r_left -> r_child = right;
	r_left -> l_child = y;
	r_left -> parent = par;
	right -> parent = y -> parent = r_left;
	right -> l_size = size(right -> l_child) + 1;
	y -> r_size = size(y -> r_child) + 1;
	r_left -> l_size = size(y) + 1;
	r_left -> r_size = size(right) + 1;
}

void insert (int x, node* y) {
	if (y -> val < x) {
		if (y -> r_child == 0) {
			//cout << "!" << endl;
			y -> r_child = new node (x, y);
			y -> r_size++;
		} else {
			//cout << "@" << y -> val << endl;
			insert (x, y -> r_child);
			y -> r_size = size(y -> r_child) + 1;
		}
	} else {
		if (y -> l_child == 0) {
			//cout << "#" << endl;
			y -> l_child = new node (x, y);
			y -> l_size++; 
		} else {
			//cout << "$" << y -> val << endl;
			insert (x, y -> l_child);
			y -> l_size = size(y -> l_child) + 1;
		}
	}
	if (y -> val == 1711848) {
		if (y -> r_child != 0) {
			//cout << "&" << y -> r_child -> val << endl;
		} 
		if (y -> l_child != 0) {
			//cout << "*" << y -> l_child -> val << endl;
		}
	}
	//cout << y -> val << " " << y -> l_size << " " << y -> r_size << endl;
	if (y -> l_size - y -> r_size > 1) {
		node* temp = y -> l_child;
		if (temp -> l_size > temp -> r_size) {
			//cout << "!" << endl;
			balance_ll(y);
		} else {
			//cout << "@" << endl;
			balance_lr(y);
		}
	} else if (y -> r_size - y -> l_size > 1) {
		node* temp = y -> r_child;
		if (temp -> l_size > temp -> r_size) {
			//cout << "#" << endl;
			balance_rl(y);
		} else {
			//cout << "$" << endl;
			balance_rr(y);
		}
	}
}

int query (int x, node* y, int z) {
	if (y == 0) {
		return z;
	}
	if (y -> val < x) {
		return query (x, y -> r_child, y -> val);
	} else {
		return query (x, y -> l_child, z);
	}
}

int main() {
	int mini = 2e9;
	root = new node(0, 0);
	bool empty = true;
	char temp[3];
	int val;
	freopen("ops.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i = 1;
	while (scanf("%s %d", temp, &val) != EOF) {
		//cout << i++ << endl;
		if (empty) {
			if (temp[0] == 'i') {
				root -> r_child = new node(val, root);
				root -> l_child = root -> r_child;
				mini = min(mini, val);
				empty = false;
			} else {
				printf("no\n");
			}
			continue;
		}
		if (temp[0] == 'i') {
			mini = min(mini, val);
			insert(val, root -> r_child);
		} else {
			if (val < mini) {
				printf("no\n");
			} else {
				printf("%d\n", query(val, root, root -> r_child -> val));
			}
		}
	}
	return 0;
}
