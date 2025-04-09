#include<iostream>
using namespace std;

int T, N, a[100006], ans;

const int M = 2e5;  // limit for array size
int n = 100006;  // array size
int t[2 * M];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        for (int i = 0; i < 2*M; i++) {
            t[i] = 0;
        }
        ans = 1;
        build();
        printf("Case #%d:", i + 1);
        for (int j = 0; j < N; j++) {
            int temp;
            scanf("%d", &temp);
            modify(1, temp + 1, 1);
            for (int k = ans; k < 100006; k++) {
                ans = max(ans, min(k, query(k)));
                if (k > query(k)) {
                    break;
                }
            }
            printf(" %d", ans);
        }
        printf("\n");
        /*for (int i = 0; i < 15; i++) {
        	cout << "!" << query(i);
        }
        cout << endl;*/
    }
    return 0;
}
