#include<iostream>
#include<unordered_set>
using namespace std;

int n, m, p[1003], v[1003];
long long dp[1003][50004];
bool a[1003][50004], b[1003][50004];
string ans;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i], &v[i]);
    ans.push_back('C');
    
    for (int j = 0; j <= m; j++) {
      if (dp[i + 1][j] == dp[i][j]) {
        a[i + 1][j] = true;
      } else if (dp[i + 1][j] < dp[i][j]) {
        b[i + 1][j] = false;
        a[i + 1][j] = true;
        dp[i + 1][j] = dp[i][j];
      }
      
      if (j + p[i] > m) {
        continue;
      }
      
      if (dp[i + 1][j + p[i]] == dp[i][j] + v[i]) {
        b[i + 1][j + p[i]] = true;
      } else if (dp[i + 1][j + p[i]] < dp[i][j] + v[i]) {
        a[i + 1][j + p[i]] = false;
        b[i + 1][j + p[i]] = true;
        dp[i + 1][j + p[i]] = dp[i][j] + v[i];
      }
    }
  }
  
  long long maxi = 0;
  for (int i = 1; i <= m; i++) {
    maxi = max(maxi, dp[n][i]);
  }
  
  unordered_set<int> us[2];
  
  for (int i = 1; i <= m; i++) {
    if (dp[n][i] == maxi) {
      us[n % 2].insert(i);
    }
  }
  
  for (int i = n; i > 0; i--) {
    us[1 - (i % 2)].clear();
    us[1 - (i % 2)].reserve(m);
    bool has_use = false, has_skip = false;
    for (auto x: us[i % 2]) {
      if (a[i][x]) {
        has_skip = true;
        us[1 - (i % 2)].insert(x);
      }
      
      if (b[i][x]) {
        has_use = true;
        us[1 - (i % 2)].insert(x - p[i - 1]);
      }
    }
    
    if (has_use && !has_skip) {
      ans[i - 1] = 'A';
    } else if (has_use && has_skip) {
      ans[i - 1] = 'B';
    }
  }
  
  cout << ans << endl;
  
  return 0;
}