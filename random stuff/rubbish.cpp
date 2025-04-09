#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, K;
bool c[100006];

struct fuxx{
    int cla, pla;
}racer[100006];

bool f(fuxx a, fuxx b) {
    return a.pla < b.pla;
}

bool g(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &racer[i].cla, &racer[i].pla);
    }
    sort(racer, racer + N, f);
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int k = upper_bound(v.begin(), v.end(), racer[i].cla, g) - v.begin();
        if (k >= v.size()) {
            v.push_back(racer[i].cla);
        } else {
            v[k] = racer[i].cla;
        }
    }
    int ans = v.size();
    printf("%d\n", ans);
    return 0;
}
