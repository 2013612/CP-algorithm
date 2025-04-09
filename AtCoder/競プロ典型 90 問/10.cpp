#include <iostream>

using namespace std;

int N, sum1[100006], sum2[100006], Q;
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int c, p;
        scanf("%d %d", &c, &p);
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        if (c == 1) {
            sum1[i] += p;
        } else {
            sum2[i] += p;
        }
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d %d\n", sum1[r] - sum1[l - 1], sum2[r] - sum2[l - 1]);
    }
    return 0;
}

