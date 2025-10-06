#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    if (s[0] == s[1]) {
        cout << s.back() << endl;
    } else {
        cout << s[0] << endl;
    }

    return 0;
}