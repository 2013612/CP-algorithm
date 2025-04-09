#include<iostream>
#include<algorithm>
using namespace std;

long long n, ans = 1;

int main() {
	scanf("%lld", &n);
	n--;
	
	int i = 0;
	long long cnt = 9;
	while (n > cnt) {
		n -= cnt;
		i++;
		if (i % 2 == 0) {
			cnt *= 10;
			ans *= 10;
		}
	}
	
	ans += n - 1;
	
	string t = to_string(ans);
	if (i % 2 == 0) {
		t.pop_back();
	}
	reverse(t.begin(), t.end());
	
	cout << ans << t << endl;
	
	return 0;
}