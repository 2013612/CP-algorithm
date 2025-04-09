#include<iostream>
using namespace std;

struct Trie {
	const static int numNode = 26;
	const static char base = 'a';
	
	struct TrieNode {
		TrieNode* children[numNode];
		bool isEnd;
		int freq;
		
		TrieNode() {
			for (int i = 0; i < numNode; i++) {
				children[i] = NULL;
			}
			isEnd = false;
			freq = 0;
		}
	};
	
	TrieNode* root;
	
	Trie() {
		root = new TrieNode();
	}
	
	int getCharIndex(char c) {
		return c - base;
	}
	
	void insert(const string &s) {
		TrieNode* cur = root;
		for (int i = 0; i < s.size(); i++) {
			cur->freq++;
			
			if (!cur->children[getCharIndex(s[i])]) {
				cur->children[getCharIndex(s[i])] = new TrieNode();
			}
			cur = cur->children[getCharIndex(s[i])];
		}
		
		cur->freq++;
		cur->isEnd = true;
	}
	
	int findMaxPrefixLen(const string &s) {
		TrieNode* cur = root;
		for (int i = 0; i < s.size(); i++) {
			if (!cur->children[getCharIndex(s[i])]) {
				return i;
			}
			cur = cur->children[getCharIndex(s[i])];
		}
		
		return s.size();
	}
	
	int dfs(TrieNode *cur) {
		int child_cnt = 0;
		int one_cnt = 0;
		int prev = 0;
		for (int i = 0; i < numNode; i++) {
			if (cur->children[i]) {
				child_cnt++;
				int res = dfs(cur->children[i]);
				if (res == 1) {
					one_cnt++;
				}
			}
		}
		
		if (one_cnt == 0) {
			return 1;
		}
		
		if (child_cnt == one_cnt) {
			return 2;
		}
		
		return 3;
	}
};

int main() {
	Trie trie = Trie();
	
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		trie.insert(s);
	}
	
	int res = trie.dfs(trie.root);
	
	if (res == 3) {
		printf("First\n");
	} else if ((res == 2) && (k & 1)) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	
	return 0;
}