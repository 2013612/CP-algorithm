#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

unordered_map<string, int> dp;
int M;
vector<int> graph[20];
queue<string> q;
int main() {
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	string s = " 000000000";
	for (int i = 1; i <= 8; i++) {
		int k;
		scanf("%d", &k);
		s[k] = '0' + i;
	}
	dp[s] = 0;
	q.push(s);
	while (!q.empty()) {
		if (dp.count(" 123456780") == 1) {
			break;
		}
		s = q.front();
		q.pop();
		int pos = 0;
		for (int i = 1; i <= 9; i++) {
			if (s[i] == '0') {
				pos = i;
				break;
			}
		}
		for (auto x:graph[pos]) {
			string temp = s;
			temp[pos] = temp[x];
			temp[x] = '0';
			if (dp.count(temp) == 0) {
				q.push(temp);
				dp[temp] = dp[s] + 1;
			}
		}
	}
	if (dp.count(" 123456780") == 1) {
		printf("%d\n", dp[" 123456780"]);
	} else {
		printf("-1\n");	
	}
	
	return 0;
}
