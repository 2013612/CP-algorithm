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
};

int dfs(Trie::TrieNode *cur, int turn) {
	int temp = -1;
	int childCnt = 0;
	int cnt[4] = {0, 0, 0, 0};
	for (int i = 0; i < Trie::numNode; i++) {
		if (cur->children[i]) {
			childCnt++;
			
			int res = dfs(cur->children[i], 1 - turn);
			
			cnt[res]++;
		}
	}
	
	if (childCnt) {
		if (cnt[2 ^ turn] || (cnt[turn] && cnt[1 - turn])) {
			temp = 2 ^ turn;
		} else if (childCnt == cnt[3 ^ turn]) {
			temp = 3 ^ turn;
		} else if (cnt[turn]) {
			temp = turn;
		} else {
			temp = 1 - turn;
		}
	} else {
		temp = 1 - turn;
	}
	
	return temp;
}

int main() {
	Trie trie = Trie();
	
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		trie.insert(s);
	}
	
	int res = dfs(trie.root, 1);
	
	if ((res == 1 && (k & 1)) || (res == 3)) {
		printf("First\n");
	} else {
		printf("Second\n");
	}
	
	return 0;
}