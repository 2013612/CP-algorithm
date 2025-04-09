#include<iostream>
using namespace std;

long long l, r, ans;

long long cal(long long a) {
	if (a < 10) {
		return 0;
	}
	
	string s = to_string(a);
	
	long long cnt = 0;
	
	long long cur = 20;
	long long add = 10;
	
	while (cur <= a) {
		int head = cur / add - 1;
		string t = to_string(cur - 1);
		long long temp = 1;
		for (int i = 0; i < t.size() - 1; i++) {
			temp *= head;
		}
		cnt += temp;
		
		if (cur == add * 10) {
			add = cur;
		}
		
		cur += add;
	}
	
	int head = s[0] - '0';
	
	long long dp[20][2];
	
	for (int i = 0; i < 20; i++) {
		dp[i][0] = dp[i][1] = 0;
	}
	
	dp[0][1] = 1;
	
	for (int i = 1; i < s.size(); i++) {
		dp[i][0] += dp[i - 1][0] * head;
		if (dp[i - 1][1]) {
			if (s[i] - '0' < head) {
				dp[i][0] += s[i] - '0';
				dp[i][1] = 1;
			} else {
				dp[i][0] += head;
			}
		}
	}
	
	cnt += dp[s.size() - 1][0] + dp[s.size() - 1][1];
	
	return cnt;
}

int main() {
	scanf("%lld %lld", &l, &r);
	
	printf("%lld\n", cal(r) - cal(l - 1));
	
	return 0;
}