#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans;
vector<int> a[11];
string S;
int main()
{
    scanf("%d", &N);
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        a[S[i] - '0'].push_back(i);
    }
    for (int i = 0; i <= 9; i++) {
        if (a[i].empty()) {
            continue;
        }
        int pos1 = a[i][0];
        for (int j = 0; j <= 9; j++) {
            int pos2 = upper_bound(a[j].begin(), a[j].end(), pos1) - a[j].begin();
            if (pos2 == a[j].size()) {
                continue;
            }
            pos2 = a[j][pos2];
            for (int k = 0; k <= 9; k++) {
                if (upper_bound(a[k].begin(), a[k].end(), pos2) != a[k].end()) {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

