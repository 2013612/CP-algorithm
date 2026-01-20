#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Trie {
	const static int base = 0;
	
	struct TrieNode {
		map<int, TrieNode*> children;
		bool isEnd;
		int freq;
		vector<int> inds;
		
		TrieNode() {
			isEnd = false;
			freq = 0;
		}
	};
	
	TrieNode* root;
	
	Trie() {
		root = new TrieNode();
	}
	
	int getCharIndex(int c) {
		return c - base;
	}
	
	TrieNode* insert(TrieNode* pos, int value, int ind) {
		TrieNode* cur = pos;
		if (!cur->children[getCharIndex(value)]) {
			cur->children[getCharIndex(value)] = new TrieNode();
		}
		
		cur = cur->children[getCharIndex(value)];
		cur->inds.push_back(ind);
		
		return cur;
	}
	
	void dfs(TrieNode* cur) {
	  for (auto x: cur->inds) {
	    if (x > 0) {
	      printf("%d ", x);
	    }
	  }
	  
	  for (auto x: cur->children) {
	    dfs(x.second);
	  }
	}
};

int n;
Trie::TrieNode* m[300005];
Trie trie;

int main() {
  scanf("%d", &n);
  
  m[0] = trie.insert(trie.root, -1, 0);
  
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    
    m[i] = trie.insert(m[x], y, i);
  }
  
  trie.dfs(m[0]);
  printf("\n");
}
