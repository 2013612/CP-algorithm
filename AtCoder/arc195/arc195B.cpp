#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;

int n, cnt1, cnt2;
vector<int> a, b;
unordered_set<int> us;

int main() {
	scanf("%d", &n);
	
	
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if (k == -1) {
			cnt1++;
		} else {
			a.push_back(k);
		}
	}
	
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if (k == -1) {
			cnt2++;
		} else {
			b.push_back(k);
		}
	}
	
	if (cnt1 + cnt2 >= n) {
		printf("Yes\n");
		return 0;
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	
	for (int i = 0; i < a.size(); i++) {
		int p = cnt2 - i;
		
		if (p < 0) {
			break;
		}
		
		for (int j = 0; j < b.size(); j++) {
			p = cnt2 - i;
			int q = cnt1;
			
			int sum = a[i] + b[j];
			
			if (sum < max(a.back(), b.front())) {
				break;
			}
			
			if (us.count(sum)) {
				continue;
			}
			
			us.insert(sum);
			
			int u = i + 1;
			int v = 0;
			
			while (u < a.size() && v < b.size()) {
				if (v == j) {
					v++;
					continue;
				}
				
				if (a[u] + b[v] < sum) {
					u++;
					q--;
				} else if (a[u] + b[v] > sum) {
					v++;
					p--;
				} else {
					u++;
					v++;
				}
			}
			
//			printf("!!! %d %d %d %d %d %d\n", i, j, p, q, u, v);
			
			p -= a.size() - u;
			q -= b.size() - v;
			
			if (p == 0 && q == 0) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	
	printf("No\n");
	
	return 0;
}
