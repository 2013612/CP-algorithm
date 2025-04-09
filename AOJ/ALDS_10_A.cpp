#include<iostream>
using namespace std;

int N;
long long a[100] = {1, 1};

int main() {
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    printf("%lld\n", a[N]);
    return 0;
}
