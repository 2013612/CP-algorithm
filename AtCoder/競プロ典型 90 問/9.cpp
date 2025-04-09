#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
#include <vector>

using namespace std;

#define PI 3.14159265
typedef pair<int, int> pii;
typedef pair<int, double> pid;

double angle(pii x, pii y) {
    return atan2(y.second - x.second, y.first - x.first) * 180 / PI + 180;
}

int N;
pii points[2004];
vector<pid> a;
double ans;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].first, &points[i].second);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            a.push_back(make_pair(i, angle(points[i], points[j])));
            a.push_back(make_pair(j, angle(points[j], points[i])));
        }
    }
    sort(a.begin(), a.end());
    for (auto x:a) {
        int pos = lower_bound(a.begin(), a.end(), make_pair(x.first, x.second + 180 - 1e-7)) - a.begin();
        if (a[pos].first != x.first) {
            ans = max(ans, min(a[pos - 1].second - x.second, 360 - (a[pos - 1].second - x.second)));
        } else {
            ans = max(ans, min(a[pos].second - x.second, 360 - (a[pos].second - x.second)));
            ans = max(ans, min(a[pos - 1].second - x.second, 360 - (a[pos - 1].second - x.second)));
        }
    }
    printf("%.9f\n", ans);
    return 0;
}

