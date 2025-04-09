#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int N;
long long ans;
pair<int, int> p[2004];
map<pair<int, int>, int> a;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (p[i].first == p[j].first) {
				a[{p[i].second, p[j].second - p[i].second}]++;
			} else {
				break;
			}
		}
	}
	for (auto x:a) {
		ans += x.second * (x.second - 1);
	}
	printf("%lld\n", ans / 2);
	return 0;
}
