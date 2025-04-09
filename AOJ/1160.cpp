#include<iostream>
#include<vector>
using namespace std;

int W, H, g[103][103], ans;
int x[10] = {1, 1, 0, -1, -1, -1, 0, 1};
int y[10] = {0, 1, 1, 1, 0, -1, -1, -1};
bool visited[103][103];

void dfs(int w, int h) {
    visited[w][h] = true;
    for (int i = 0; i < 8; i++) {
        if (g[w + x[i]][h + y[i]] == 1 && !visited[w + x[i]][h + y[i]]) {
            dfs(w + x[i], h + y[i]);
        }
    }
}

int main()
{
    while (true) {
        scanf("%d %d", &W, &H);
        if (W == 0 && H == 0) {
            break;
        }
        ans = 0;
        for (int i = 0; i <= H + 1; i++) {
            for (int j = 0; j <= W + 1; j++) {
                g[i][j] = 0;
                visited[i][j] = false;
            }
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                scanf("%d", &g[i][j]);
            }
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (g[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
