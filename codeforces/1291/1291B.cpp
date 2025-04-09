#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int T, N, a[400006], ans;
int main(){
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int maxi = 0;
		int pos = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[j]);
			if (a[j] > maxi) {
				maxi = a[j];
				pos = j;
			} else if (a[j] == maxi) {
				if (abs(pos - N/2) > abs(j - N/2)) {
					pos = j;
				}
			}
		}
		for (int )
	}
	printf("%d\n", ans);
	return 0;
}
