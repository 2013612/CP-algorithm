#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

long long N, K, ans;
map<long long, long long> my_map;
set<long long> my_set;
vector<long long> A, B;
int main() {
	scanf("%lld %lld", &N, &K);
	for (int i = 0; i < N; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		my_map[a] += b;
		my_set.insert(a);
	}
	A.push_back(0);
	for (auto x:my_set) {
		A.push_back(x);
	}
	sort(A.begin(), A.end());
	B.push_back(0);
	for (int i = 1; i < A.size(); i++) {
		B.push_back(my_map[A[i]]);
	}
	ans = K;
	for (int i = 1; i < A.size(); i++) {
		if (ans >= A[i]) {
			ans += B[i];
		} else {
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
