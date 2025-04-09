#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

long long n, t, s[200006];
unordered_map<long long, int> um;

int main() {
	scanf("%lld %lld", &n, &t);
	um[0] = n;
	
	for (int i = 0; i < t; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		um[s[a]]--;
		if (um[s[a]] == 0) {
			um.erase(s[a]);
		}
		s[a] += b;
		um[s[a]]++;
		printf("%d\n", um.size());
	}
	
	return 0;
}