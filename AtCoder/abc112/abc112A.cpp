#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N;
int main(){
	scanf("%d", &N);
	if (N == 1) {
		printf("Hello World\n");
	} else {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
