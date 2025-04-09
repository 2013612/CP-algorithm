#include<iostream>
using namespace std;

long long N, ans;
int main() {
  scanf("%lld", &N);
  int factor = 0;
  for (long long i = 2; i * i <= N && N > 1; ) {
    if (N % i == 0) {
    	factor++;
      N /= i;
    } else {
    	i++;
    }
  }
  if (N > 1) {
    factor++;
  }
  while(factor > 1) {
    factor = (factor + 1) / 2;
    ans++;
  }
  printf("%lld\n", ans);
  return 0;
}
