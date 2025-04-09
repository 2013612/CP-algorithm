#include <iostream>
#include <atcoder/all>

using namespace atcoder;

int H, W, Q;
dsu d(4000007);
bool red[2004][2004];
int main()
{
    scanf("%d %d", &H, &W);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int r, c;
            scanf("%d %d", &r, &c);
            red[r][c] = true;
            if (red[r + 1][c]) {
                d.merge(r * W + c, (r + 1) * W + c);
            }
            if (red[r - 1][c]) {
                d.merge(r * W + c, (r - 1) * W + c);
            }
            if (red[r][c + 1]) {
                d.merge(r * W + c, r * W + c + 1);
            }
            if (red[r][c - 1]) {
                d.merge(r * W + c, r * W + c - 1);
            }
        } else {
            int r1, c1, r2, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            if (red[r1][c1] && red[r2][c2] && d.same(r1 * W + c1, r2 * W + c2)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}

