#include<iostream>
using namespace std;

int p, q, x, y;

int main() {
  scanf("%d %d", &p, &q);
  scanf("%d %d", &x, &y);
  
  if (x >= p && y >= q && x - p < 100 && y - q < 100) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
}