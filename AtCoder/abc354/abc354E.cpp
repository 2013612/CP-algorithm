#include<iostream>
#include<bitset>
#include<unordered_map>
using namespace std;

int n, a[20], b[20];
unordered_map<bitset<20>, bool> um;

bool dfs(bitset<20> cur) {
	if (um.count(cur)) {
		return um[cur];
	}
	
	bool can = false;
	
	for (int i = 0; i < n - 1; i++) {
		if (cur[i]) {
			for (int j = i + 1; j < n; j++) {
				if (cur[j] && (a[i] == a[j] || b[i] == b[j])) {
					bitset<20> t = cur;
					t[i] = false;
					t[j] = false;
					can = dfs(t) || can;
				}
			}
		}
	}
	
	um[cur] = !can;
	
	return um[cur];
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	
	bitset<20> s;
	s.set();
	
	if (!dfs(s)) {
		printf("Takahashi\n");
	} else {
		printf("Aoki\n");
	}
	
	return 0;
}