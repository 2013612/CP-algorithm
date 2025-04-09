#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int n, m, q, a[1003];
vector<pair<int, int>> diff;
map<int, vector<int>> mp;
set<int> ans, used;

int find(int x) {
	if (a[x] == x) {
		return x;
	}
	
	return a[x] = find(a[x]);
}

void merge(int x, int y) {
	int ny = find(y);
	int nx = find(x);
	a[ny] = nx;
	for (int i = 0; i < mp[ny].size(); i++) {
		mp[nx].push_back(mp[ny][i]);
	}
	mp.erase(ny);
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		mp[i].push_back(i);
	}
	
	for (int i = 1; i <= n; i += 2) {
		printf("? %d %d\n", i, i + 1);
		fflush(stdout);
		int t;
		scanf("%d", &t);
		
		if (t == 0) {
			merge(i, i + 1);
		} else {
			diff.push_back({i, i + 1});
		}
	}

	for (int i = 1; i <= n; ) {
		int a = i;
		while (a < n && (used.count(find(a)) || mp[find(a)].size() != 2)) {
			a++;
		}
		used.insert(find(a));
		int b = a + 1;
		while (b < n && (used.count(find(b)) || mp[find(b)].size() != 2)) {
			b++;
		}
		
		if (b >= n || used.count(find(b)) || mp[find(b)].size() != 2) {
			break;
		}
		
		used.insert(find(b));
		
		printf("? %d %d\n", a, b);
		fflush(stdout);
		int t;
		scanf("%d", &t);
		if (t == 0) {
			merge(a, b);
		} else {
			for (int i = 0; i < mp[find(a)].size(); i++) {
				diff.push_back({mp[find(a)][i], mp[find(b)][i]});
			}
		}
		i = b + 1;
	}
	
	used.clear();
	
	for (int i = 1; i <= n; ) {
		int a = i;
		while (a < n && (used.count(find(a)) || mp[find(a)].size() != 4)) {
			a++;
		}
		used.insert(find(a));
		int b = a + 1;
		while (b < n && (used.count(find(b)) || mp[find(b)].size() != 4)) {
			b++;
		}
		
		if (b >= n || used.count(find(b)) || mp[find(b)].size() != 4) {
			break;
		}
		used.insert(find(b));
		
		printf("? %d %d\n", a, b);
		fflush(stdout);
		int t;
		scanf("%d", &t);
		if (t == 0) {
			merge(a, b);
		} else {
			for (int i = 0; i < mp[find(a)].size(); i++) {
				diff.push_back({mp[find(a)][i], mp[find(b)][i]});
			}
		}
		i = b + 1;
	}
	
	if (diff.size() != m) {
		if (diff.size() == 2) {
			int k1, k2;
			used.clear();
			for (int i = 1; i <= n; ) {
				int a = i;
				while (a < n && (used.count(find(a)) || mp[find(a)].size() != 8)) {
					a++;
				}
				used.insert(find(a));
				int b = a + 1;
				while (b < n && (used.count(find(b)) || mp[find(b)].size() != 8)) {
					b++;
				}
				
				if (b >= n || used.count(find(b)) || mp[find(b)].size() != 8) {
					break;
				}
				used.insert(find(b));
				
				printf("? %d %d\n", a, b);
				fflush(stdout);
				int t;
				scanf("%d", &t);
				if (t == 0) {
					merge(a, b);
				} else {
					k1 = a;
					k2 = b;
					break;
				}
				i = b + 1;
			}
			
			for (int i = 1; i <= n; i++) {
				if (find(i) == find(k1) || find(i) == find(k2) || mp[find(i)].size() < 8) {
					continue;
				}
				printf("? %d %d\n", i, k1);
				fflush(stdout);
				int t;
				scanf("%d", &t);
				int fk;
				if (t == 0) {
					fk = k2;
				} else {
					fk = k1;
				}
				for (auto x: mp[fk]) {
					ans.insert(x);
				}
				break;
			}
		} else {
			for (int i = 1; i <= 1000; i++) {
				bool can = true;
				for (int j = 0; j < diff.size(); j++) {
					if (diff[j].first == i || diff[j].second == i) {
						can = false;
						break;
					}
				}
				if (can && mp[find(i)].size() == 4) {
					ans.insert(i);
				}
			}
		}
		
		for (int i = 0; i < diff.size(); i++) {
			printf("? %d %d\n", diff[i].first, *ans.begin());
			fflush(stdout);
			int t;
			scanf("%d", &t);
			if (t == 0) {
				ans.insert(diff[i].first);
			} else {
				ans.insert(diff[i].second);
			}
		}
		
	} else {
		vector<int> t1, t2;
		for (int i = 1; i <= n; i++) {
			if (find(i) == find(diff[0].first) || mp[find(i)].size() < 8) {
				continue;
			}
			printf("? %d %d\n", i, diff[0].first);
			fflush(stdout);
			int t;
			scanf("%d", &t);
			if (t == 0) {
				t1.push_back(i);
			} else {
				t2.push_back(i);
			}
			
			if (t1.size() == 2) {
				ans.insert(diff[0].second);
				break;
			} else if (t2.size() == 2) {
				ans.insert(diff[0].first);
				break;
			}
		}
		
		for (int i = 1; i < diff.size(); i++) {
			printf("? %d %d\n", diff[i].first, *ans.begin());
			fflush(stdout);
			int t;
			scanf("%d", &t);
			if (t == 0) {
				ans.insert(diff[i].first);
			} else {
				ans.insert(diff[i].second);
			}
		}
	}
	
	printf("!");
	for (auto x: ans) {
		printf(" %d", x);
	}
	printf("\n");
	
	return 0;
}