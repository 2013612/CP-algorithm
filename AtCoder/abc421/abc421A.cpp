#include<bits/stdc++.h>
using namespace std;

int n, a[300005], ans;
string s[103];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i + 1];
	}

    string x;
    cin >> ans >> x;
	
    if (s[ans] == x) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
	
	return 0;
}