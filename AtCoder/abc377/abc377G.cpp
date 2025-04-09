#include<iostream>
#include<set>
using namespace std;

struct TrieNode {
	int len;
	TrieNode* children[26];
	
	TrieNode() {
		len = 1e9;
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
	}
};

void insert(TrieNode* root, string s) {
	TrieNode* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (!cur->children[s[i] - 'a']) {
			cur->children[s[i] - 'a'] = new TrieNode();
		}
		cur = cur->children[s[i] - 'a'];
		cur->len = min<int>(cur->len, s.size());
	}
}

int find(TrieNode* root, string s) {
	int ans = s.size();
	TrieNode* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (!cur->children[s[i] - 'a']) {
			break;
		}
		cur = cur->children[s[i] - 'a'];
		
		ans = min<int>(ans, s.size() + cur->len - 2 * (i + 1));
	}
	
	return ans;
}

int n;

int main() {
	TrieNode* root = new TrieNode();
	root->len = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		printf("%d\n", find(root, s));
		insert(root, s);
	}
}