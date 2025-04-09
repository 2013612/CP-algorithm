#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, a;
char k[200];
string s, t;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		scanf("%s", k);
		s = k;
		t = k;
		reverse(t.begin(), t.end());
		bool success = true;
		for (int j = 0; j < a/2; j++) {
			if (s[j] != t[j] && s[j] + 2 != t[j] && s[j] - 2 != t[j]) {
				success = false;
				break;
			}
		}
		if (success) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
