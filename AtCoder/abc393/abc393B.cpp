#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
string s;

int main() {
	cin >> s;
	n = s.size();
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			for (int j = i + 1; j < n; j++) {
				if (j + j - i >= n) {
					break;
				}
				
				if (s[j] == 'B' && s[j + j - i] == 'C') {
					ans++;
				}
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}