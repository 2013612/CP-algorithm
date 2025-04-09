#include<iostream>
#include<string>
using namespace std;

int N;

void solve(int left, string S) {
	if (S.length() == N) {
      cout << S << endl;
      return;
    }
  if ((S.length() - left) / 2 + left < N / 2) {
   	solve(left + 1, S + "("); 
  }
  if (left > 0) {
    solve(left - 1, S + ")");
  }
}

int main() {
  scanf("%d", &N);
  if (N % 2 == 0) {
    solve(0, "");
  }
  return 0;
}
