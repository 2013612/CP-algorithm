#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans;
int main(){
	scanf("%d %d", &N, &ans);
	if (N % 2 == 1 && ans % 2 == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}
