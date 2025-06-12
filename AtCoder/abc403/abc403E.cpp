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
	
	bool check(string &s) {
		TrieNode* cur = root;
		for (int i = 0; i < s.size(); i++) {
			if (cur->isEnd) {
				return false;
			}
			
			if (!cur->children[getCharIndex(s[i])]) {
				return true;
			}
			cur = cur->children[getCharIndex(s[i])];
		}
		
		return !(cur->isEnd);
	}
	
	void erase(string &s) {
		TrieNode* cur = root;
		for (int i = 0; i < s.size(); i++) {
			if (!cur->children[getCharIndex(s[i])]) {
				return;
			}
			cur = cur->children[getCharIndex(s[i])];
		}
		
		int t = cur->freq;
		cur = root;
		for (int i = 0; i < s.size(); i++) {
			cur->freq -= t;
			cur = cur->children[getCharIndex(s[i])];
		}
		
		cur->freq = 0;
		cur->isEnd = false;
		
		for (int i = 0; i < numNode; i++) {
			cur->children[i] = NULL;
		}
	}
};

int main() {
	int q;
	scanf("%d", &q);
	
	Trie x = Trie();
	Trie y = Trie();
	
	for (int i = 0; i < q; i++) {
		int t;
		string s;
		cin >> t >> s;
		
		if (t == 1) {
			y.erase(s);
			x.insert(s);
		} else {
			if (x.check(s)) {
				y.insert(s);
			}
		}
		
		printf("%d\n", y.root->freq);
	}
}