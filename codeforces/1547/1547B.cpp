#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int T, ans;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		int left = 0;
		int right = s.length() - 1;
		for (int j = right; j >= 0; j--) {
			if (s[left] == 'a' + j) {
				left++;
			} else if (s[right] == 'a' + j) {
				right--;
			} else {
				printf("NO\n");
				break;
			}
			if (j == 0) {
				printf("YES\n");
			}
		}
	}
	return 0;
}
