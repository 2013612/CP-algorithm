#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
string s;

int main() {
    cin >> s;
    n = s.length();

    sort(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            cout << s[i];
            s.erase(i, 1);
            break;
        }
    }

    cout << s << endl;

    return 0;
}