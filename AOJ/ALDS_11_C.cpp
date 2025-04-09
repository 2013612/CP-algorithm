#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, dis[103];
vector<int> a[103];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int q, M;
        scanf("%d %d", &q, &M);
        for (int j = 1; j <= M; j++) {
            int temp;
            scanf("%d", &temp);
            a[q].push_back(temp);
        }
        dis[q] = -1;
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (auto x:a[y]) {
            if (dis[x] == -1) {
                dis[x] = dis[y] + 1;
                q.push(x);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d %d\n", i, dis[i]);
    }
    return 0;
}
