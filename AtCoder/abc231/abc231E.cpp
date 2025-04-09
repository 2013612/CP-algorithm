#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int n;
long long a[103], ans, x;
unordered_map<long long, long long> um;
unordered_set<long long> us;

long long solve(long long t) {
	if (um.count(t) == 1) {
		return um[t];
	}
	us.insert(t);
	int ind = lower_bound(a, a + n, t) - a;
	
	long long temp = t / a[ind - 1] + solve(t % a[ind - 1]); 
	
	if (us.count(a[ind] - t) == 0 && ind != n) {
		temp = min(temp, 1 + solve(a[ind] - t));
	}

	um[t] = temp;
	us.erase(t);
	return um[t];
}

int main() {
	scanf("%d %lld", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		um[a[i]] = 1;
	}
	um[0] = 0;
	printf("%lld\n", solve(x));
	return 0;
}
