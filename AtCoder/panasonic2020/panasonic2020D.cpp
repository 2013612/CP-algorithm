#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N;
string t;
vector<string> ans;
int main() {
	scanf("%d", &N);
	ans.push_back("a");
	t.push_back('a');
	int pos = 0;
	for (int i = 2; i <= 10; i++) {
		int pos2 = ans.size();
		for (int j = pos; j < pos2; j++) {
			string temp = ans[j];
			for (int k = 0; k <= t[j] - 'a' + 1; k++) {
				string temp2 = temp;
				temp2.push_back('a' + k);
				ans.push_back(temp2);
				t.push_back(max(temp2.back(), t[j]));
			}
		}
		pos = pos2;
	}
	for (auto x:ans) {
		if (x.length() == N) {
			cout << x << endl;
		}
	}
	return 0;
}
