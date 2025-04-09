#include<iostream>
#include<unordered_map>
using namespace std;

const int M = 998244353;

int n, a[103];
long long ans[103];
unordered_map<int, unordered_map<int, long long>> um[103];

int main() {
	scanf("%d", &n);
	
	ans[1] = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		
		for (int j = i - 1; j >= 0; j--) {
			um[i][a[i] - a[j]][2] = (1ll * um[i][a[i] - a[j]][2] + 1) % M;
			ans[2] = (1ll * ans[2] + 1) % M;
			for (auto [u, v]: um[j][a[i] - a[j]]) {
				um[i][a[i] - a[j]][u + 1] = (1ll * um[i][a[i] - a[j]][u + 1] + v) % M;
				ans[u + 1] = (1ll * ans[u + 1] + v) % M;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}