#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int ans;
string S, T;
int main() {
	cin >> S >> T;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != T[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
