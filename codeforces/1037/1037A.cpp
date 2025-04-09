#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;
int main(){
	scanf("%d", &N);
	int num = 1;
	for (int i = 0; i < 40; i++) {
		if (N < num) {
			printf("%d\n", i);
			return 0;
		}
		num *= 2;
	}
	return 0;
}
