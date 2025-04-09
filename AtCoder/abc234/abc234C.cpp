#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long k;
string ans;
int main() {
	scanf("%lld", &k);
	for (int i = 0; k != 0; k >>= 1) {
		if (k & 1) {
			ans.push_back('2');
		} else {
			ans.push_back('0');
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
