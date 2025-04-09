#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
typedef pair<int, int> pii;

int n, m, dis[200006][20];
queue<pii> q;
bool edge[20][20];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    for (int i = 0; i < (1 << n); i++) {
    	for (int j = 0; j < n; j++) {
    		dis[i][j] = 1e9;
		}
    }
    dis[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dis[1 << i][i] = 1;
        q.push({1 << i, i});
    }
    while (!q.empty()) {
        int k = q.front().first;
        int pos = q.front().second;
        q.pop();
        
        for (int i = 0; i < n; i++) {
        	int new_k = k ^ (1 << i);
        	if (edge[pos][i] && dis[new_k][i] == 1e9) {
        		dis[new_k][i] = dis[k][pos] + 1;
        		q.push({new_k, i});
			}
		}
    }
    int sum = 0;
    for (int i = 0; i < (1 << n); i++) {
    	int ans = 1e9;
    	for (int j = 0; j < n; j++) {
    		ans = min(ans, dis[i][j]);
		}
        sum += ans;
    }
    printf("%d\n", sum);
    return 0;
}
