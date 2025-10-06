#include<bits/stdc++.h>
using namespace std;

int t;
int sx1, sy1, sx2, sy2;
int tx1, ty1, tx2, ty2;
double ds, dt;

double dis(int x1, int y1, int x2, int y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

double dis(double t) {
    double x1 = sx2;
    double y1 = sy2;
    if (t < ds) {
        x1 = sx1 + t * (sx2 - sx1) / ds;
        y1 = sy1 + t * (sy2 - sy1) / ds;
    }

    double x2 = tx2;
    double y2 = ty2;
    if (t < dt) {
        x2 = tx1 + t * (tx2 - tx1) / dt;
        y2 = ty1 + t * (ty2 - ty1) / dt;
    }

    double dx = x2 - x1;
    double dy = y2 - y1;

    return sqrt(dx * dx + dy * dy);
}

void solve() {
    scanf("%d %d %d %d", &sx1, &sy1, &sx2, &sy2);
    scanf("%d %d %d %d", &tx1, &ty1, &tx2, &ty2);

    ds = dis(sx1, sy1, sx2, sy2);
    dt = dis(tx1, ty1, tx2, ty2);

    double ans = dis(1e9);

    int cnt = 0;
    double l = 0, r = min(ds, dt);
    while (abs(dis(l) - dis(r)) > 1e-10 || cnt < 100) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if (dis(m1) < dis(m2)) {
            r = m2;
        } else {
            l = m1;
        }

        cnt++;
    }
    ans = min(ans, dis(r));

    l = min(ds, dt);
    r = max(ds, dt);

    cnt = 0;
    while (abs(dis(l) - dis(r)) > 1e-10 || cnt < 100) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if (dis(m1) < dis(m2)) {
            r = m2;
        } else {
            l = m1;
        }

        cnt++;
    }
    ans = min(ans, dis(r));    

    printf("%.9lf\n", ans);
}

int main() {
    scanf("%d", &t);
    
    while (t-- > 0) {
        solve();
    }

    return 0;
}