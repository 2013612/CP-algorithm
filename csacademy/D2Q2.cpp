#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

const int MOD = 1000000007
int n, x, a[100006], F[MOD];
vector<int> v;

int add_seq(int k) {
	int temp = 100000;
	int ans = 0;
	while(temp > 2) {
		temp = lower_bound(F + 1, F[MOD], k) - F;
		v.push_back(F[temp-1]);
		k = F[temp-2];
		ans++;
	}
	v.reverse();
	return ans;
} 

void check_seq() {
	int k = v[0];
	while(true) {
		int temp = lower_bound(F + 1, F[MOD], k) - F;
		if (temp > 2 && !binary_search(v.begin(), v.end(), F[temp-2]) && !binary_search(v.begin(), v.end(), F[temp-1])) {
			int p = lower_bound(v.begin(), v.end(), k);
			v.insert(p, F[temp-2]);
			v.insert(p, F[temp-1]);
			v.erase(p);
			k = F[temp-2];
		} else {
			if (k == v.back()) {
				break;
			} else {
				k = v[lower_bound(v.begin(), v.end(), k) - v.begin() + 1];
			}
		}
	}
}

void add_ele(int k) {
	int temp = 
	while() {
		if (!binary_search(v.begin(), v.end(), F[k])) {
			v.insert(lower_bound(v.begin(), v.end(), F[k]), F[k]);
		} else {
			
		}
	}
}
int main() {
	scanf("%d", &n);
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i < MOD; i++) {
		F[i] = (F[i-1] + F[i-2]) % MOD;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		int num = F[x];
		if (i == 0) {
			printf("%d ", add_seq(num));
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
