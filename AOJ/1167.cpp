#include<iostream>
#include<vector>

using namespace std;

vector<long long> all, odd;
int dpall[203][1000007], dpodd[203][1000007];

int main()
{
    odd.push_back(0);
    for (int i = 0; i * (i + 1) * (i + 2) / 6 <= 1e6; i++) {
        all.push_back(i * (i + 1) * (i + 2) / 6);
        if ((i * (i + 1) * (i + 2) / 6) & 1) {
            odd.push_back(i * (i + 1) * (i + 2) / 6);
        }
    }
    for (int j = 1; j <= 1e6; j++) {
        dpall[0][j] = 1e9;
        dpodd[0][j] = 1e9;
    }
    for (int i = 1; i < all.size(); i++) {
        for (int j = 1; j <= 1e6; j++) {
            if (j >= all[i]) {
                dpall[i % 2][j] = min(dpall[(i + 1) % 2][j], dpall[i % 2][j - all[i]] + 1);
            } else {
                dpall[i % 2][j] = dpall[(i + 1) % 2][j];
            }
        }
    }
    for (int i = 1; i < odd.size(); i++) {
        for (int j = 1; j <= 1e6; j++) {
            if (j >= odd[i]) {
                dpodd[i % 2][j] = min(dpodd[(i + 1) % 2][j], dpodd[i % 2][j - odd[i]] + 1);
            } else {
                dpodd[i % 2][j] = dpodd[(i + 1) % 2][j];
            }
        }
    }
    while (true) {
        int N;
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        printf("%d %d\n", dpall[(all.size() - 1) % 2][N], dpodd[(odd.size() - 1) % 2][N]);
    }
    return 0;
}
