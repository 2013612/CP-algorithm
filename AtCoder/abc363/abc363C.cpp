#include<iostream>
#include<algorithm>
using namespace std;

int n, k, ans;
string s;

bool check_parlindrome() {
	for (int i = 0; i < n - k + 1; i++) {
		string t = s.substr(i, k);
		for (int j = 0; j < k / 2; j++) {
			if (t[j] != t[k - j - 1]) {
				break;
			}
			
			if (j == k / 2 - 1) {
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	scanf("%d %d", &n, &k);
	
	cin >> s;
	
	sort(s.begin(), s.end());
	
	do {
		ans += check_parlindrome();
	} while (next_permutation(s.begin(), s.end()));
	
	printf("%d\n", ans);
	
	return 0;
}