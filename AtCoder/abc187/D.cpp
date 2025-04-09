#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int N;
long long A, B;
pair<long long, long long> vote[200006];

bool f(pair<long long, long long> a, pair<long long, long long> b) {
	return (2 * a.first + a.second) > (2 * b.first + b.second);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &vote[i].first, &vote[i].second);
		A += vote[i].first;
	}
	sort(vote, vote + N, f);
	
	for (int i = 0; i < N; i++) {
		if (B > A) {
			//printf("%d %d\n", A, B);
			printf("%d\n", i);
			return 0;
		} else {
			B += vote[i].first + vote[i].second;
			A -= vote[i].first;
		}
	}
	
	printf("%d\n", N);
	return 0;
}
