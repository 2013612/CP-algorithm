#include<iostream>
using namespace std;

long long N, a[100006];
int main() {
	scanf("%lld", &N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
  	scanf("%lld", &a[i]);
    sum += a[i];
  }
  if (sum % 10 != 0) {
    printf("No\n");
    return 0;
  } else {
    sum /= 10;
  }
  int l = 0;
  int r = 0;
  long long int_sum = 0;
  while (l < N) {
    if (int_sum == sum) {
      printf("Yes\n");
      return 0;
    } else if (int_sum < sum) {
    	int_sum += a[r];
      r++;
      r %= N;
    } else {
      int_sum -= a[l];
      l++;
    }
  }
  printf("No\n");
}
