#include <iostream>
#include <string>

using namespace std;

long long N, ans;
string S;
int main()
{
    scanf("%lld", &N);
    cin >> S;
    ans = N * (N + 1) / 2;
    long long cou = 1;
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1]) {
            cou++;
        } else {
            ans -= cou * (cou + 1) / 2;
            cou = 1;
        }
    }
    ans -= cou * (cou + 1) / 2;
    printf("%lld\n", ans);
    return 0;
}

