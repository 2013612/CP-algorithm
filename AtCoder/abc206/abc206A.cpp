#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, ans;
int main() {
	scanf("%d", &N);
	if (108 * N / 100 < 206) {
		printf("Yay!\n");
	} else if (108 * N / 100 == 206) {
		printf("so-so\n");
	} else {
		printf(":(\n");
	}
	return 0;
}
