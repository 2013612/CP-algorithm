#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

string S;
unordered_map<string, long long> cnt;
long long a[30];
long long ans;
int main() {
	cin >> S;
	long long N = S.length();
	for (int i = 0; i < N; i++) {
		string temp;
		temp.push_back(S[i]);
		cnt[temp] += 1;
		a[S[i] - 'a']++;
	}
	for (int i = 0; i < N; i++) {
		a[S[i] - 'a']--;
		for (int j = 0; j < 26; j++) {
			string temp;
			temp.push_back(S[i]);
			temp.push_back('a' + j);
			//cout << temp << endl;
			cnt[temp] += a[j];
		}
	}
	for (auto x:cnt) {
		//cout << x.first << " " << x.second << endl;
		ans = max(ans, x.second);
	}
	printf("%lld\n", ans);
	return 0;
}
