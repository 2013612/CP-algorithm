#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int H, W;
bool visited[200][200];

int f(int a, int b) {
    return 100 * a + b;
}

bool check(int a, int b) {
    return a > 0 && b > 0 && a < 110 && b < 110;
}

int main()
{
    while (true) {
        scanf("%d %d", &W, &H);
        if (H == 0 && W == 0) {
            break;
        }
        vector<int> edge[5004];
        for (int i = 0; i < 2 * H - 1; i++) {
            if (i & 1) {
                for (int j = 0; j < W; j++) {
                    int temp;
                    scanf("%d", &temp);
                    if (temp == 0) {
                        edge[f(i / 2, j)].push_back(f(i / 2 + 1, j));
                        edge[f(i / 2 + 1, j)].push_back(f(i / 2, j));
                    }
                }
            } else {
                for (int j = 0; j < W - 1; j++) {
                    int temp;
                    scanf("%d", &temp);
                    if (temp == 0) {
                        edge[f(i / 2, j)].push_back(f(i / 2, j + 1));
                        edge[f(i / 2, j + 1)].push_back(f(i / 2, j));
                    }
                }
            }
        }
        queue<int> q;
        q.push(f(0, 0));
        int dis[5004];
        for (int i = 0; i < 5000; i++) {
            dis[i] = -1;
        }
        dis[0] = 1;
        while (!q.empty()) {
            for (auto z:edge[q.front()]) {
                if (dis[z] == -1) {
                    dis[z] = dis[q.front()] + 1;
                    q.push(z);
                }
            }
            q.pop();
        }
        printf("%d\n", max(dis[f(H - 1, W - 1)], 0));
    }
    return 0;
}
