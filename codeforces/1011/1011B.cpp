#include<iostream>
using namespace std;

int n, m, a[102], b, part;
bool success[100];

int main() {
	scanf("%d %d\n", &n, &m);
	if (n > m) {
		printf("0\n");
	} else {
		for (int i = 0; i < m; i++) {
			scanf("%d", &b);
			a[b]++;
		}
		part = n;
		for (int i = 1; i <= m/n; i++){
			for (int j = 1; j <= 100; j++){
				part -= a[j]/i;
				if (part <= 0){
					success[i] = true;
					break;
				}
			}
			if (!success[i]){
				printf("%d\n", i - 1);
				break;
			} else if (i == m/n){
				printf("%d\n", i);
			}
			part = n;
		}
	}
	return 0;
}
