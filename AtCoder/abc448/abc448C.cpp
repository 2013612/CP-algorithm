#include<iostream>
#include<set>
using namespace std;

int n, q, a[300005];
multiset<int> ms;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ms.insert(a[i]);
    }

    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        int b[k];
        for (int j = 0; j < k; j++) {
            scanf("%d", &b[j]);
            b[j]--;
            ms.erase(ms.find(a[b[j]]));
        }

        printf("%d\n", *ms.begin());
        for (int j = 0; j < k; j++) {
            ms.insert(a[b[j]]);
        }
    }

    return 0;
}