#include<iostream>
#include<set>
using namespace std;

int N, s[12], M, p[10][12];
set<string> ans;

string change(string str, int index) {
	str = " " + str;
	char temp[11];
	for (int i = 1; i <= N; i++) {
		temp[p[index][i]] = str[i];
	}
	string ret = "";
	for (int i = 1; i <= N; i++) {
		ret += temp[i];
	}
	return ret;
}

void com(string str, set<int> used, set<string> &con) {	
	ans.insert(str);
		
	if (used.size() == M) {
		return;
	}
	
	for (int i = 1; i <= M; i++) {
		if (used.find(i) == used.end()) {
			used.insert(i);
			com(change(str, i), used, con);
			used.erase(i);
		}
	}
}

int main() {
	scanf("%d", &N);
	string str = "";
	for (int i = 1; i <= N; i++) {
		scanf("%d", &s[i]);
		str += '0' + s[i] - 1;
	}
	
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	//cout << change(str, 1) << endl;
	//ans.insert(str);
	set<int> used;
	com(str, used, ans);
	string k = *ans.begin();
//	for (auto x:ans) {
//		cout << x << endl;
//		k = min(k, x);
//	}
	for (int i = 0; i < N; i++) {
		printf("%c ", k[i] + 1);
	}
	printf("\n");
	return 0;
}
