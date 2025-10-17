#include<iostream>
#include<set>
using namespace std;

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int h, w, ans;
string s[300005];
set<pair<int, int>> v;

bool in(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
    scanf("%d %d", &h, &w);

    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                v.insert({i, j});
            }
        }
    }

    while (v.size()) {
        set<pair<int, int>> t = v;
        v.clear();

        for (auto [p, q]: t) {
            s[p][q] = '#';
        }

        for (auto [p, q]: t) {
            for (int i = 0; i < 4; i++) {
                int new_p = p + x[i];
                int new_q = q + y[i];
                if (!in(new_p, new_q)) {
                    continue;
                }

                if (s[new_p][new_q] == '#') {
                    continue;
                }

                int cnt = 0;

                for (int j = 0; j < 4; j++) {
                    int nnp = new_p + x[j];
                    int nnq = new_q + y[j];

                    if (!in(nnp, nnq)) {
                        continue;
                    }

                    if (s[nnp][nnq] == '#') {
                        cnt++;
                    }
                }

                if (cnt == 1) {
                    v.insert({new_p, new_q});
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}