#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a[200006], b[10], ans;

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= 13; i++) {
		for (int j = 0; j < 4; j++) {
			b[j] = a[j];
		}
		b[4] = i;
		sort(b, b + 5);
		
		if (b[0] == b[1] && b[2] == b[3] && b[3] == b[4] && b[1] != b[2]) {
			printf("Yes\n");
			return 0;
		} else if (b[0] == b[1] && b[1] == b[2] && b[3] == b[4] && b[2] != b[3]) {
			printf("Yes\n");
			return 0;
		}
	}
	
	printf("No\n");
	
	return 0;
}