#include<iostream>
#include<queue>
#include<set>
using namespace std;

string s = "ACDEHIJKMORST";
int l[100006], r[100006];
char ans[100006];
set<char> fi[100006], se[100006];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = ' ';
		fi[i].clear();
		se[i].clear();
	}
	
	for (int i = 1; i <= n; i++) {
		if (l[l[i]] == i || l[r[i]] == i || r[l[i]] == i || r[r[i]] == i) {
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (ans[i] != ' ') {
			continue;
		}
		queue<int> q;
		q.push(i);
		ans[i] = s[0];
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto y: fi[x]) {
				se[l[x]].insert(y);
				se[r[x]].insert(y);
			}
			fi[l[x]].insert(ans[x]);
			fi[r[x]].insert(ans[x]);
			if (ans[l[x]] == ' ') {
				set<char> temp;
				for (auto y: fi[l[x]]) {
					temp.insert(y);
				}
				for (auto y: se[l[x]]) {
					temp.insert(y);
				}
				temp.insert(ans[l[l[x]]]);
				temp.insert(ans[r[l[x]]]);
				temp.insert(ans[l[l[l[x]]]]);
				temp.insert(ans[l[r[l[x]]]]);
				temp.insert(ans[r[l[l[x]]]]);
				temp.insert(ans[r[r[l[x]]]]);
				for (int j = 0; j < s.size(); j++) {
					if (temp.count(s[j]) == 0) {
						ans[l[x]] = s[j];
						q.push(l[x]);
						break;
					}
					if (j == s.size() - 1) {
						printf("IMPOSSIBLE\n");
						return;
					}
				}
			}
			
			if (ans[r[x]] == ' ') {
				set<char> temp;
				for (auto y: fi[r[x]]) {
					temp.insert(y);
				}
				for (auto y: se[r[x]]) {
					temp.insert(y);
				}
				temp.insert(ans[l[r[x]]]);
				temp.insert(ans[r[r[x]]]);
				temp.insert(ans[l[l[r[x]]]]);
				temp.insert(ans[l[r[r[x]]]]);
				temp.insert(ans[r[l[r[x]]]]);
				temp.insert(ans[r[r[r[x]]]]);
				for (int j = 0; j < s.size(); j++) {
					if (temp.count(s[j]) == 0) {
						ans[r[x]] = s[j];
						q.push(r[x]);
						break;
					}
					if (j == s.size() - 1) {
						printf("IMPOSSIBLE\n");
						return;
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%c", ans[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}