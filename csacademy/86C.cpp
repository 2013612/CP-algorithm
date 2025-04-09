#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

char s[1000];
string S;
bool k[1000];

int main(){
	scanf("%s", s);
	S = s;
	int ans = 0;
	for (int i = 1; i < S.length(); i++) {
		if (S[i] == S[i-1] && !k[i-1]) {
			ans++;
			k[i] = true;
			continue;
		}
		if (i > 1 && S[i] == S[i-2] && !k[i-2]) {
			ans++;
			k[i] = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}
