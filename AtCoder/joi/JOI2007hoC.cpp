#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int N, ans;
pii a[3003];

int len2(pii x, pii y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

bool search(int x, int y) {
    return binary_search(a, a + N, make_pair(x, y));
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a + N);
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int xdiff = a[j].first - a[i].first;
            int ydiff = a[j].second - a[i].second;
            if (ydiff >= 0) {
                if (search(a[j].first + ydiff, a[j].second + xdiff) && search(a[i].first + ydiff, a[i].second + xdiff)) {
                    ans = max(ans, len2(a[i], a[j]));
                }
                if (search(a[j].first - ydiff, a[j].second - xdiff) && search(a[i].first - ydiff, a[i].second - xdiff)) {
                    ans = max(ans, len2(a[i], a[j]));
                }
            } else {
                if (search(a[j].first + ydiff, a[j].second - xdiff) && search(a[i].first + ydiff, a[i].second - xdiff)) {
                    ans = max(ans, len2(a[i], a[j]));
                }
                if (search(a[j].first - ydiff, a[j].second + xdiff) && search(a[i].first - ydiff, a[i].second + xdiff)) {
                    ans = max(ans, len2(a[i], a[j]));
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

