#include<iostream>
#include<queue>
using namespace std;

int N, a[100006];
char b[100006];
struct node{
	char val;
	int fre;
	node* left, * right;
	node (char x = '0', int y = 0) {
		val = x;
		fre = y;
		left = nullptr;
		right = nullptr;
	}
};

struct CompareFre{
	bool operator()(node x, node y) {
		return x.fre > y.fre;
	}
};

priority_queue<node, vector<node>, CompareFre> huffman;

void build() {
	while(huffman.size() > 1) {
		node temp1 = huffman.top();
		huffman.pop();
		node temp2 = huffman.top();
		huffman.pop();
		node temp3 = node('0', temp1.fre + temp2.fre);
		temp3.left = new node();
		*temp3.left = temp1;
		temp3.right = new node();
		*temp3.right = temp2;
		//cout << temp3.left -> val << " " << temp3.left -> fre << endl;
		huffman.push(temp3);
	}
	return;
}

void print(node x) {
	cout << x.val << " " << x.fre << endl;
	if (x.left != nullptr) {
		print(*x.left);
	}
	if (x.right != nullptr) {
		print(*x.right);
	}
	return;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> b[i] >> a[i];
		node temp = node(b[i], a[i]);
		//cout << temp.val << " " << temp.fre << endl;
		huffman.push(temp);
	}
	build();
	print(huffman.top());
	return 0;
}
