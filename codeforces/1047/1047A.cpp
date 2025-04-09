#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int main(){
	scanf("%d", &N);
	if (N % 3 == 0) {
		printf("1 1 %d", N - 2);
	} else {
		printf("1 2 %d", N - 3);
	}
	return 0;
}
