#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int M = 998244353;

int n, q, ind_a[200006], ind_b[200006], o[200006], x[200006];
pair<int, int> a[200006], b[200006];
vector<long long> ans;

long long power(long long a, int x) {
	if (x == 0) {
		return 1;
	}
	
	if (x & 1) {
		return 1ll * a * power(a, x - 1) % M;
	} else {
		long long t = power(a, x / 2);
		return t * t % M;
	}
}

long long inv(long long a) {
	return power(a, M - 2);
}

void solve() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &o[i], &x[i]);
		x[i]--;
	}
	
	ans.clear();
	
	sort(a, a + n);
	sort(b, b + n);
	
	ans.push_back(1);
	for (int i = 0; i < n; i++) {
		ans.back() *= min(a[i].first, b[i].first);
		ans.back() %= M;
		ind_a[a[i].second] = i;
		ind_b[b[i].second] = i;
	}
	
	for (int i = 0; i < q; i++) {
		ans.push_back(ans.back());
		if (o[i] == 1) {
			int ia = ind_a[x[i]];
			int ind = upper_bound(a, a + n, make_pair(a[ia].first, 2 * n)) - a - 1;
			
			ans.back() *= inv(min(a[ia].first, b[ia].first));
			ans.back() %= M;
			
			a[ia].first++;
			if (ind != ia) {
				ans.back() *= inv(min(a[ind].first, b[ind].first));
				ans.back() %= M;
			
				ind_a[x[i]] = ind;
				ind_a[a[ind].second] = ia;
				
				swap(a[ind], a[ia]);
				
				ans.back() *= min(a[ind].first, b[ind].first);
				ans.back() %= M;
			}
			
			ans.back() *= min(a[ia].first, b[ia].first);
			ans.back() %= M;
		} else {
			int ib = ind_b[x[i]];
			int ind = upper_bound(b, b + n, make_pair(b[ib].first, 2 * n)) - b - 1;
			
			ans.back() *= inv(min(a[ib].first, b[ib].first));
			ans.back() %= M;
			
			b[ib].first++;
			if (ind != ib) {
				ans.back() *= inv(min(a[ind].first, b[ind].first));
				ans.back() %= M;
			
				ind_b[x[i]] = ind;
				ind_b[b[ind].second] = ib;
				
				swap(b[ind], b[ib]);
				
				ans.back() *= min(a[ind].first, b[ind].first);
				ans.back() %= M;
			}
			
			ans.back() *= min(a[ib].first, b[ib].first);
			ans.back() %= M;
		}
//		
//		printf("a: ");
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//				if (a[k].second == j) {
//					printf("%d ", a[k].first);
//				}
//			}
//		}
//		printf("\n");
//		
//		printf("b: ");
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//				if (b[k].second == j) {
//					printf("%d ", b[k].first);
//				}
//			}
//		}
//		printf("\n");
//		printf("\n");
//		
//		printf("a: ");
//		for (int j = 0; j < n; j++) {
//			printf("{%d %d %d}", a[j].first, a[j].second, ind_a[a[j].second]);
//		}
//		printf("\n");
//		
//		printf("b: ");
//		for (int j = 0; j < n; j++) {
//			printf("{%d %d}", b[j].first, b[j].second);
//		}
//		printf("\n");
//		printf("\n");
	}
	
	for (auto x: ans) {
		printf("%lld ", x);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		solve();
	}
	return 0;
}