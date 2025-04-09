#include<iostream>
#include<unordered_map>
using namespace std;

int k;
string s, t;
unordered_map<int, int> um[2];

int main() {
	scanf("%d", &k);
	cin >> s;
	cin >> t;
	
	int n = s.size();
	int m = t.size();

	for (int i = 0; i <= min(k, m); i++) {
		um[0][i] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		int cur = i % 2;
		int prev = 1 - i % 2;
		um[cur].clear();
		
		if (i <= k) {
			um[cur][0] = i;
		}
		
		for (int j = max(1, i - k); j <= min(i + k, m); j++) {
			if (s[i - 1] == t[j - 1]) {
				if (um[prev].count(j - 1)) {
					um[cur][j] = um[prev][j - 1];
				}
			} else {
				int temp = 1e9;
				if (um[prev].count(j - 1)) {
					temp = min(temp, um[prev][j - 1]);
				}
				if (um[prev].count(j)) {
					temp = min(temp, um[prev][j]);
				}
				if (um[cur].count(j - 1)) {
					temp = min(temp, um[cur][j - 1]);
				}
				
				if (temp + 1 <= k) {
					um[cur][j] = temp + 1;
				}
			}
		}
	}
	
	if (um[n % 2].count(m)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}