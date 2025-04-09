#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, t[4];
string a, b;
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0' && b[i] == '0') {
			t[0]++;
		} else if (a[i] == '0' && b[i] == '1'){
			t[1]++;
		} else if (a[i] == '1' && b[i] == '0') {
			t[2]++;
		} else {
			t[3]++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0' && b[i] == '0') {
			ans += t[3] + t[2];
			t[0]--;
		} else if (a[i] == '0' && b[i] == '1') {
			ans += t[2];
			t[1]--;
		} else if (a[i] == '1' && b[i] == '0') {
			ans += t[0] + t[1];
			t[2]--;
		} else {
			ans += t[0];
			t[3]--;
		}
	}
	cout << ans;
	return 0;
}
