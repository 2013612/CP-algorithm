#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N, S, a[200006];
int main(){
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	bool k = binary_search(a, a + N, S);
	long long ans = 0;
	//if (k) {
		int pos = lower_bound(a, a + N, S) - a;
		if (pos != N/2) {
			if (pos > N/2) {
				for (int i = N/2; i < pos; i++) {
					ans += S - a[i];
				}
			} else {
				for (int i = pos; i <= N/2; i++) {
					ans += a[i] - S;
				}
			}
		} else {
			ans += a[pos] - S;
		}
	//}
	printf("%lld\n", ans);
	return 0;
}
