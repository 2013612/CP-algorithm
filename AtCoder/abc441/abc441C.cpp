#include<iostream>
#include<algorithm>
using namespace std;

int n, k, a[300005], ans = -1;
long long x;

int main() {
  scanf("%d %d %lld", &n, &k, &x);
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  sort(a, a + n);
  
  long long sum = 0;
  for (int i = k - 1; i >= 0; i--) {
    sum += a[i];
    
    if (sum >= x) {
      ans = n - i;
      break;
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}