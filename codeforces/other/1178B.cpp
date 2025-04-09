#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s;
vector<int> k, o;
int main() {
	cin >> s;
	if (s.size() < 5) {
		cout << 0 << endl;
		return 0;
	}
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'v') {
			count++;
		} else {
			if (count != 0) {
				k.push_back(count - 1);
				//cout << k.back() << endl;
			}
			count = 0;
		}
	}
	if (count != 0) {
		k.push_back(count - 1);
	}
	count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'o') {
			count++;
		} else {
			if (count != 0) {
				o.push_back(count);
			}
			count = 0;
		}
	}
	o.push_back(count);
	vector<int> sum, sum2;
	sum2.push_back(k.back());
	sum.push_back(k[0]);
	//cout << k.back() << endl;
	for (int i = 1; i < k.size(); i++) {
		sum.push_back(sum.back() + k[i]);
		//cout << sum.back() << endl;
	}
	//cout << "!" << endl;
	for (int i = k.size() - 2; i >= 0; i--) {
		sum2.push_back(sum2.back() + k[i]);
		//cout << sum2.back() << endl;
	}
	//cout << "@" << endl;
	int first = 0;
	if (s[0] == 'o') {
		first = 1;
	}
	long long ans = 0;
	for (int i = 0; i < sum.size() - 1; i++) {
		ans += 1ll * (sum[i]) * (sum2[sum.size() - i - 2]) * o[i + first];
		//cout << ans << endl;
	}
	printf("%lld\n", max(ans, 1ll*0));
	return 0;
}
