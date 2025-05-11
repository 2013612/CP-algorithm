#include<bits/stdc++.h>
using namespace std;

int k, n, ans, last;
vector<int> l, r;

void solve() {
	scanf("%d %d", &n, &k);
	ans = 0;
	
	if (n == 2 * k) {
		printf("! %d %d\n", k, k);
		fflush(stdout);
		return;
	}
	
	l.clear();
	r.clear();
	for (int i = 1; i <= k; i++) {
		printf("? %d\n", i);
		fflush(stdout);
		int p;
		scanf("%d", &p);
		l.push_back(p);
	}
	
	
	{
		for (int i = n - k + 1; i <= n; i++) {
			printf("? %d\n", i);
			fflush(stdout);
			int p;
			scanf("%d", &p);
			r.push_back(p);
			
			if (i == n) {
				last = p;
			}
		}
		
		int t = n % k;
		if (t > 0) {
			t = k - t;
			rotate(r.begin(), r.begin() + t, r.end());
		}
	}
	
	int ind = -1;
	{
		for (int i = 0; i < k; i++) {
			if (l[i] != r[i]) {
				ind = i;;
				break;
			}
		}
		
		if (ind < 0) {
			printf("! -1\n");
			fflush(stdout);
			return;
		}
	}
	
//	printf("$$ ind: %d\n", ind);
	
	int u = 0, v = (n - 1) / k;
	
	while (u + 1 < v) {
		int mid = (u + v) / 2;
		
//		printf("$$ mid: %d k: %d ind: %d\n", mid, k, ind);
		printf("? %d\n", mid * k + ind + 1);
		fflush(stdout);
		int p;
		scanf("%d", &p);
		
		if (p == l[ind]) {
			u = mid;
		} else {
			v = mid;
		}
	}
	
	int cnt = 0;
	int le = max(u * k + ind, k);
	int ri = min(u * k + ind + k, n - k - 1);
	for (int i = le; i <= ri; i++) {
		int t = i;
		
		printf("? %d\n", t + 1);
		fflush(stdout);
		int p;
		scanf("%d", &p);
		
		if (p != l[t % k]) {
			if (cnt > 0) {
				printf("! -1\n");
			} else {
				printf("! %d %d\n", t, n - t);
			}
			
			fflush(stdout);
			return;
		} else {
			if (p == r[t % k]) {
				cnt++;
			} else {
				cnt = 0;
			}
		}
	}
	
	int t = ri + 1;
	if (cnt > 0) {
		printf("! -1\n");
	} else {
		printf("! %d %d\n", t, n - t);
	}
	
	fflush(stdout);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}