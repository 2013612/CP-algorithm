#include<iostream>
#include<string>
using namespace std;

int ans;
string s;
long long M;
int main() {
	cin >> s >> M;
	int cou = s[0] - '0' + 1;
	for (__int128 i = s[0] - '0' + 1; i <= M; i++) {
		//cout << ++cou << endl;
		bool overflow = false;
		__int128 base = i;
		__int128 num = 0;
		for (int j = 0; j < s.length(); j++) {
			num = num * base + (s[j] - '0');
			if (num > M) {
				overflow = true;
				break;
			}
		}
		if (overflow) break;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
