#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n, a[27];
char s[100006];
int main(){
	scanf("%d", &n);
	scanf("%s", s);
	if (n > 26 || n == 1) {
		printf("Yes\n");
	} else {
		bool success = false;
		for (int i = 0; i < n; i++) {
			a[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (a[i] >= 2) {
				success = true;
				break;
			}
		}
		if (success) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
