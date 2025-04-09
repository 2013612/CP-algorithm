#include<iostream>
#include<vector>
using namespace std;

long long N, a[1004], ans;
vector<long long> b;
int main() {
	scanf("%lld", &N);
	long long maxi = 0;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
		maxi = max(maxi, a[i]);
	}
	int bit = 0;
	for (int i = 0; i <= 62; i++) {
		if (a[i] < (long long)(1 << i)) {
			bit = i - 1;
		}
	}
	int count = 0;
	long long test = (long long)(1 << bit);
	for (int i = 0; i < N; i++) {
		if (a[i] & test) {
			b.push_back(a[i]);
		}
	}
	
	return 0;
}
