#include<iostream>
using namespace std;

int n, cnt[10];

int main() {
	scanf("%d", &n);
	
	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}
	
	if (cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}