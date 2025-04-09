#include<iostream>
#include<algorithm>
using namespace std;

int n, a[1000007], c[40];
bool b[1000007];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int num = 0;
	c[0] = 1;
	for (int i = 1; i < 31; i++) {
		c[i] = c[i-1] * 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 32; j++) {
			if (c[j] - a[i] == a[i]) {
				if (a[i-1] == a[i] || a[i] == a[i+1]) {
					b[i] = true;
					break;
				} 
			} else if (binary_search(a, a+n, c[j] - a[i])) {
				b[i] = true;
				break;
			}
		}
		if (!b[i]) {
			num++;
		}
	}
	printf("%d\n", num);
	return 0;
}
