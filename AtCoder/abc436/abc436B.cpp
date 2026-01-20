#include<iostream>
using namespace std;

int n, ans[100][100];

int main() {
  scanf("%d", &n);
  
  int x = 0, y = (n + 1) / 2 - 1;
  
  for (int i = 0; i < n * n; i++) {
    ans[x][y] = i + 1;
    if (!ans[(x + n - 1) % n][(y + 1) % n]) {
      x = (x + n - 1) % n;
      y = (y + 1) % n;
    } else {
      x = (x + 1) % n;
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
