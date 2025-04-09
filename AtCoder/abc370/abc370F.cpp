#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, k, a[400006];
bool b[200006];
vector<vector<int>> v;
unordered_map<int, vector<int>> um;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[n + i] = a[i];
	}
	
	int l = 1;
	int r = 2e9;
	
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		int l1 = 0;
		int r1 = 0;
		int sum = 0;
		um.clear();
		v.clear();
		while (r1 < 2 * n) {
			if (sum < mid) {
				sum += a[r1];
				r1++;
			} else {
				if (!um.count(l1)) {
					v.push_back(vector<int>(1, l1));
					um[l1].push_back(v.size() - 1);
				}
				int maxi = 0;
				int ind = -1;
				for (int x: um[l1]) {
					if (r1 - v[x][0] > n) {
						continue;
					}
					v[x].push_back(r1);
					if (v[x].size() > k) {
						continue;
					}
					
					if (v[x][0] > maxi) {
						maxi = v[x][0];
						ind = x;
					}
				}
				
				if (ind >= 0) {
					um[r1].push_back(ind);
				}
				
				um.erase(l1);
				sum -= a[l1];
				l1++;
			}
		}
		bool can = false;
		for (auto x: v) {
			if (x.size() > k) {
				can = true;
				break;
			}
		}
		
		if (can) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	{
		int l1 = 0;
		int r1 = 0;
		int sum = 0;
		um.clear();
		v.clear();
		while (r1 < 2 * n) {
			if (sum < l) {
				sum += a[r1];
				r1++;
			} else {
				if (!um.count(l1)) {
					v.push_back(vector<int>(1, l1));
					um[l1].push_back(v.size() - 1);
				}
				int maxi = 0;
				int ind = -1;
				for (int x: um[l1]) {
					if (r1 - v[x][0] > n) {
						continue;
					}
					v[x].push_back(r1);
					if (v[x].size() > k) {
						continue;
					}
					
					if (v[x][0] > maxi) {
						maxi = v[x][0];
						ind = x;
					}
				}
				
				if (ind >= 0) {
					um[r1].push_back(ind);
				}
				
				um.erase(l1);
				sum -= a[l1];
				l1++;
			}
		}
	}
	
	for (auto x: v) {
		if (x.size() <= k) {
			continue;
		}
		for (auto y: x) {
//			printf("%d ", y);
			b[y % n] = true;
		}
//		printf("\n");
		
		int end = x[0];
		if (end < x.back()) {
			end += n;
		}
		for (int i = x.back(); i < end; i++) {
			b[i % n] = true;
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += !b[i];
	}
	
	printf("%d %d\n", l, cnt);
	
	return 0;
}