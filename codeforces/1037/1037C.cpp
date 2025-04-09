#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;
char a[2000006], b[2000006];
int main(){
	scanf("%d", &N);
	scanf("%s", a);
	scanf("%s", b);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			if (i != N - 1 && a[i + 1] != b[i + 1] && a[i] != a[i + 1]) {
				a[i + 1] = b[i + 1];
			}
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
