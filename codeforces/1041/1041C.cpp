#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, D, a[200006], b[200006], c[200006];

int main(){
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + N);
	int temp;
	int day = 1;
	for (int i = 0; i < N; i++) {
		if (c[i] == 0) {
			int pos = i;
			while (pos < N) {
				temp = b[pos];
				c[pos] = day;
				temp += D + 1;
				pos = lower_bound(b, b + N, temp) - b;
				while (c[pos] > 0) {
					pos++;
				}
			}
			day++;
		}
	}
	printf("%d\n", day - 1);
	for (int i = 0; i < N; i++) {
		int temp = lower_bound(b, b + N, a[i]) - b;
		printf("%d ", c[temp]);
	}
	return 0;
} 
