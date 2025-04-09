#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, a[1004], ans;
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i < N; i++) {
		if (a[i - 2] == 1 && a[i - 1] == 0 && a[i] == 1) {
			ans++;
			a[i] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
