#include<iostream>
#include<utility>
#include<deque>
using namespace std;

long long ans, N, S, sum;
deque<pair<long long, long long>> deq;

int main() {
	scanf("%lld %lld", &N, &S);
	sum = 0;
	for (int i = 0; i < N; i++) {
		long long c, d;
		scanf("%lld %lld", &c, &d);
		while (d > 0) {
			if (deq.empty() || deq.front().first >= c) {
				ans += c * d;
				break;
			}
			
			long long mini = min(d, deq.front().second);
			ans += deq.front().first * mini;
			sum -= mini;
			d -= mini;
			
			if (deq.front().second > d) {
				deq.front().second -= mini;
			} else {
				deq.pop_front();
			}
		}
		
		while (!deq.empty() && deq.back().first >= c) {
			sum -= deq.back().second;
			deq.pop_back();
		}
		deq.push_back(make_pair(c, S - sum));
		sum += S - sum;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
