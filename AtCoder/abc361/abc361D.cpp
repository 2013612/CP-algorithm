#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int n;
string s, t;
unordered_map<string, int> um;
queue<string> q;

int main() {
	scanf("%d", &n);
	cin >> s >> t;
	s += "..";
	t += "..";
	um[s] = 0;
	q.push(s);
	while (!q.empty() && !um.count(t)) {
		string k = q.front();
		q.pop();
		
		int dot = 0;
		for (int i = 0; i < k.size(); i++) {
			if (k[i] == '.') {
				dot = i;
				break;
			}
		}
		for (int i = 0; i < n + 1; i++) {
			string u = k.substr(i, 2);
			if (u[0] != '.' && u[1] != '.') {
				string v = k.substr(0, i) + ".." + k.substr(i + 2);
				v[dot] = u[0];
				v[dot + 1] = u[1];
				
				if (!um.count(v)) {
					um[v] = um[k] + 1;
					q.push(v);
				}
			}
		}
	}
	
	if (!um.count(t)) {
		printf("-1\n");
	} else {
		printf("%d\n", um[t]);
	}
	
	return 0;
}