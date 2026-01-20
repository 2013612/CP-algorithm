#include<iostream>
using namespace std;

int n;
string s;

int main() {
  scanf("%d", &n);
  cin >> s;
  for (int i = s.length(); i < n; i++) {
    s = "o" + s;
  }
  
  cout << s << endl;
}
