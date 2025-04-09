#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int T, l, r;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &l, &r);
		printf("%d %d\n", l, 2*l);
	}
	return 0;
}
