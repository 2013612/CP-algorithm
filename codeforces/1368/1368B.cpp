#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long N, ans, A[103];
string S;
int main() {
	scanf("%lld", &N);
	int count = 0;
	S = "codeforces";
	for (int i = 0; ; i++) {
		long long total = 1;
		for (int j = 0; j < 10; j++) {
			total *= A[j];
		}
		if (total >= N) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < A[j]; k++) {
					printf("%c", S[j]);
				}
			}
			break;
		} else {
			A[count]++;
			count++;
			count = count % 10; 
		}
	}
	return 0;
}
