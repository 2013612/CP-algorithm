#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int M, H;
int main() {
	scanf("%d %d", &M, &H);
	if (H % M == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
