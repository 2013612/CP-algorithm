#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[103], b[103], num[2];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[a[i]]++;
	}
	for (int i = 0; i < 103; i++) {
		if (b[i] == 1) {
			num[0]++;
		} else if (b[i] > 2) {
			num[1]++;
		}
	}
	if (num[0] % 2 == 1 && num[1] == 0) {
		printf("NO\n");
	} else {
		printf("YES\n");
		if (num[0] % 2 == 0) {
			int count = 0;
			for (int i = 0; i < N; i++) {
				if (b[a[i]] == 1 && count < num[0]/2) {
					printf("B");
					count++;
				} else {
					printf("A");
				}
			}
		} else {
			int count = 0;
			bool extra = false;
			for (int i = 0; i < N; i++) {
				if ((b[a[i]] == 1 && count < num[0]/2) || (!extra && b[a[i]] > 2)) {
					printf("B");
					if (b[a[i]] == 1) {
						count++;
					} else {
						extra = true;
					}
				} else {
					printf("A");
				}
			}
		}
	}
	return 0;
}
