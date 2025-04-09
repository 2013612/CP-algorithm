#include<iostream>
using namespace std;

int N, L, K, a[100006];

bool can(int w) {
	int temp = K + 1;
  int last = 0;
  for(int i = 1; i <= N + 1 && temp > 0; i++) {
  	if (a[i] - a[last] >= w) {
     temp--; 
      last = i;
    }
  }
  return temp == 0;
}

int main() {
  scanf("%d %d", &N, &L);
  scanf("%d", &K);
  a[0] = 0;
  a[N + 1] = L;
  for (int i = 1; i <= N; i++) {
  	scanf("%d", &a[i]);
  }
  int l = 0;
  int r = 1e9 + 7;
  while (l < r) {
  	int mid = l + (r - l + 1) / 2;
    if (can(mid)) {
    	l = mid;
    } else {
    	r = mid - 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
