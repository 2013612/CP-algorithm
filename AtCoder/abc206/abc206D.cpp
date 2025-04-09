#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<atcoder/all>
using namespace atcoder;

int N, ans, a[200006];
dsu d(200006);
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < N / 2; i++) {
		if (!d.same(a[i], a[N - i - 1])) {
          	//printf("%d\n", i);
			ans++;
			d.merge(a[i], a[N - i - 1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
