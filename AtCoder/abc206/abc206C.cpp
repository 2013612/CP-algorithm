#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int N;
long long ans;
unordered_map<int, int> uo;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		uo[temp]++;
	}
	for (auto x:uo) {
		ans += 1ll * (N - x.second) * x.second;
	}
	printf("%lld\n", ans / 2);
	return 0;
}
