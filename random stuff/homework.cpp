#include<iostream>
#include<string>
using namespace std;

struct node{
	int val;
	bool exist;
	node *child[26];
	node(int new_val = 0){
		val = new_val;
		for (int i = 0; i<26;i++){
			child[i] = NULL;
		}
		exist = false;
	}
	bool find (char a){
		if (child[a-'A'] == NULL){
			return false;
		}
		else {
			return true;
		}
	}
};

int main(){
	node *root = new node();
	string a,b;
	int times = 0;
	while(times<10){
		cin >> a >> b;
		if (a == "insert"){
			node *cur = root;
			for (int i = 0; i<b.length();i++){
				if (cur -> find(b[i])){
					cur = cur -> child[b[i]-'A'];
				}
				else {
					cur -> child[b[i] - 'A'] = new node();
					cur = cur -> child[b[i]-'A'];
				}
			}
			cin >> cur -> val;
			cur -> exist = true;
		}
		else {
			node *cur = root;
			bool find = true;
			for (int i =0;i<b.length();i++){
				if (cur -> find(b[i])){
					cur = cur -> child[b[i]-'A'];
				}
				else {
					find = false;
					break;
				}
			}
			if (cur -> exist == false || find == false){
				cout << b << " not found" << endl;
			}
			else {
				cout << cur -> val << endl;
			}
		}
		times++;
	}
	return 0;
}
