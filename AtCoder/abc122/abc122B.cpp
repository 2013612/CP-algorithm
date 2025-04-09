#include<iostream>
#include<string>
using namespace std;

string S;
int ans;
int main() {
	cin >> S;
	int leng = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
			leng++;
		} else {
			ans = max(ans, leng);
			leng = 0;
		}
	}
	ans = max(ans, leng);
	printf("%d\n", ans);
	return 0;
}
