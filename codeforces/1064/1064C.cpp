#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, a[26], ans;
char c[100006];
int main(){
	scanf("%d", &N);
	scanf("%s", c);
	for (int i = 0; i < N; i++) {
		a[c[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (a[i]) {
			for (int j = 0; j < a[i]; j++) {
				printf("%c", 'a' + i);
			}
		}
	}
	return 0;
}
