#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, K;
char s[103];
int main(){
	scanf("%d %d", &N, &K);
	scanf("%s", s);
	for (int i = 1; i < N; i++) {
		bool success = true;
		for (int j = 0, k = i; k < N; j++, k++) {
			if (s[j] != s[k]) {
				success = false;
				break;
			}
		}
		if (success) {
			for (int j = 0; j < K - 1; j++) {
				for (int k = 0; k < i; k++) {
					printf("%c", s[k]);
				}
			}
			for (int j = 0; j < N; j++) {
				printf("%c", s[j]);
			}
			printf("\n");
			return 0;
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c", s[j]);
		}
	}
	printf("\n");	
	return 0;
}
