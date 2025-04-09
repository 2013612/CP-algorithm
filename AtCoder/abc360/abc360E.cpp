#include<iostream>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

mint n, k, ans = 1;

int main() {
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k.val(); i++) {
		ans = ((ans + 1) * n - (2 * ans - 1)) / n;
	}
	
	printf("%d\n", ans.val());
	
	return 0;
}