#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[500006], b[500006], ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (i == 0) {
			b[i] = a[i];
			continue;
		}
		b[i] = b[i - 1]^a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j += 2) {
			int mid = (i + j - 1)/2;
			if (i == 0) {
				if (b[mid] == (b[j] ^ b[mid])) {
					ans++;
				}
				continue;
			}
			if ((b[mid] ^ b[i - 1]) == (b[j] ^ b[mid])) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
