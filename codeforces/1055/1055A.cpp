#include<iostream>
using namespace std;

int N, S, a[1004], b[1004];
int main(){
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	if (a[0] == 0) {
		printf("NO");
	} else {
		if (a[S - 1] == 1) {
			printf("YES");
		} else {
			if (b[S - 1] == 0) {
				printf("NO");
			} else {
				for (int i = S; i < N; i++) {
					if (a[i] == 1 && b[i] == 1) {
						printf("YES");
						return 0;
					}
				}
				printf("NO");
			}
		}
	}
	return 0;
}
