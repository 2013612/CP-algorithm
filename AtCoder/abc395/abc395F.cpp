#include<iostream>
using namespace std;

long long n, u[200005], v[200005], x, ans;

int main() {
	scanf("%lld %lld", &n, &x);
	
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &u[i], &v[i]);
	}
	
	long long l = 0, r = u[0] + v[0] + 1;
	
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		
		bool can = true;
		long long up = 1e18;
		long long dn = -1e18;
		
		for (int i = 0; i < n; i++) {
			if (u[i] + v[i] < mid) {
				can = false;
				break;
			}
			
			long long t = u[i] + v[i] - mid;
			long long cur_up, cur_dn;
			if (v[i] >= t) {
				cur_up = u[i];
			} else {
				cur_up = u[i] - (t - v[i]);
			}
			
			if (u[i] >= t) {
				cur_dn = u[i] - t;
			} else {
				cur_dn = 0;
			}
			
			cur_up = min(cur_up, up + x);
			cur_dn = max(cur_dn, dn - x);
			
			if (cur_up < cur_dn) {
				can = false;
				break;
			}
			
			up = cur_up;
			dn = cur_dn;
		}
		
		if (can) {
			l = mid;
		} else {
			r = mid;
		}
	}
	
	for (int i = 0; i < n; i++) {
		ans += u[i] + v[i] - l;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}