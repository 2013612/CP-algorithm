#include<iostream>
using namespace std;

int n, w[100006], h[100006];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &w[i], &h[i]);
	}
	int k = max(w[0], h[0]);
	for (int i = 1; i < n; i++){
		if (k >= w[i] && k >= h[i]){
			k = max(w[i], h[i]);
		} else if (k >= w[i] && k < h[i]){
			k = w[i];
		} else if (k < w[i] && k >= h[i]){
			k = h[i];
		} else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
