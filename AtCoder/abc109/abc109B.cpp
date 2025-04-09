#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans;
string a[103];
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < N; i++) {
		if (a[i][0] != a[i - 1].back()) {
			printf("No\n");
			return 0;
		}
	}
	sort(a, a + N);
	for (int i = 0; i < N - 1; i++) {
		if (a[i].compare(a[i + 1]) == 0) {
			printf("No\n");
			return 0;
		}
	} 
	printf("Yes\n");
	return 0;
}
