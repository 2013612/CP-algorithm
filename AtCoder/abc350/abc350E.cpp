#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long n, a, x, y;
double ans;
unordered_map<long long, double> um;

double solve(long long p) {
	if (p == 0) {
		return 0;
	}
	
	if (um.count(p)) {
		return um[p];
	}
//	cout << p << endl;
	
	um[p] = min(x + solve(p / a), (6 * y + solve(p / 2) + solve(p / 3) + solve(p / 4) + solve(p / 5) + solve(p / 6)) / 5);
	
//	cout << p << " " << x + um[p / a] << " " << (6 * y + um[p / 2] + um[p / 3] + um[p / 4] + um[p / 5] + um[p / 6]) / 5 << endl;
//	cout << p << " " << um[p] << endl;
	return um[p];
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &a, &x, &y);
	solve(n);
	
	printf("%.9f\n", um[n]);
	
	return 0;
}