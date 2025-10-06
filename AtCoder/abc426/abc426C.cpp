#include<bits/stdc++.h>
using namespace std;

int n, q, ans;
map<int, int> m;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        m[i + 1] = 1;
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        int sum = 0;

        while ((*m.begin()).first <= x) {
            sum += (*m.begin()).second;
            m.erase(m.begin());
        }

        printf("%d\n", sum);

        m[y] += sum;
    }

    return 0;
}