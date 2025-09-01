#include<bits/stdc++.h>
using namespace std;

int n;
long long ans1, ans2;
vector<int> v;
string s;

int main() {
	scanf("%d", &n);

	cin >> s;

	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == 'A') {
			v.push_back(i);
		}
	}

	for (int i = 0; i < n; i++) {
		ans1 += abs(2 * i - v[i]);
		ans2 += abs(2 * i + 1 - v[i]);
	}
	
	printf("%lld\n", min(ans1, ans2));
	
	return 0;
}