#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, a[], ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", ans);
	return 0;
}
