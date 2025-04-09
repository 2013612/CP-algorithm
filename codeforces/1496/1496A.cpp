#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, N, K;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		bool ans = false;
		string s;
		scanf("%d %d", &N, &K);
		cin >> s;
		if (K == 0) {
			printf("YES\n");
			continue;
		} else if (N % 2 == 0) {
			printf("NO\n");
			continue;
		}
		string a = s.substr(0, N / 2);
		string b = s.substr(N / 2 + 1, N / 2);
		reverse(b.begin(), b.end());
		if (a == b) {
			ans = true;
		}
		if (ans) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
