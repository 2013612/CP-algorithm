#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[100006], ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	printf("%d\n", a[N - 1] - a[0] + 1 - N);
	return 0;
} 
