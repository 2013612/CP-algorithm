#include <iostream>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> edge[100006];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        int cou = 0;
        for (auto x:edge[i]) {
            if (x < i) {
                cou++;
            }
        }
        if (cou == 1) {
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

