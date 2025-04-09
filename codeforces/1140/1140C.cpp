#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int K, N;
long long ans;
pair<int, int> a[400006], b[400006];

bool f(pair<int, int> x, pair<int, int> y) {
	if (x.second > y.second) {
		return true;
	} else if (x.second == y.second) {
		if (x.first > y.first) {
			return true;
		}
	}
	return false;
}

bool g(pair<int, int> x, pair<int, int> y) {
	return x > y;
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
		b[i] = a[i];
	}
	sort(a, a + N, f);
	sort(b, b + N, g);
	for (int i = 0; i < N; i++) {
		long long temp = 0;
		int j = 0;
		int k = 0;
		while (j < i + 1 && j < K) {
			if (b[k].second >= a[i].second) {
				temp += b[k].first;
				j++;
			}
			k++;
		}
		ans = max(ans, temp * a[i].second);
	}
	printf("%lld\n", ans);
	return 0;
}
