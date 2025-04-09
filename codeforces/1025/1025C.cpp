#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
string s;
bool isW;
int main(){
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) {
		s.push_back(s[i]);
	}
	int ans = 1;
	for (int i = 0; i < n;) {
		int length = 1;
		if (s[i] == 'b') {
			isW = false;
		} else {
			isW = true;
		}
		for (int j = i + 1; j < i + n; j++) {
			if (isW) {
				if (s[j] == 'b') {
					length++;
					isW = false;
				} else {
					i = j;
					break;
				}
			} else {
				if (s[j] == 'w') {
					length++;
					isW = true;
				} else {
					i = j;
					break;
				}
			}
		}
		ans = max(ans, length);
		if (ans == n) {
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
