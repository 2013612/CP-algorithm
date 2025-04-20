#include<bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> mp;
long long ans;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		
		int x = (b + a) % n;
		
		ans += i - mp[x];
		
		mp[x]++;
	}
	
	printf("%lld\n", ans);
	return 0;
}