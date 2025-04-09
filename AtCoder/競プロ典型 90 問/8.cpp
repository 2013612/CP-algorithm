#include <iostream>
#include <string>

using namespace std;

const int M = 1e9 + 7;
const string atcoder = " atcoder";

long long N, a[100006][11];
string S;
int main()
{
    scanf("%lld", &N);
    cin >> S;
    a[0][0] = 1;
    if (S[0] == 'a') {
        a[0][1] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < atcoder.length(); j++) {
            a[i][j] = a[i - 1][j];
            if (S[i] == atcoder[j]) {
                a[i][j] += a[i - 1][j - 1];
                a[i][j] %= M;
            }
        }
    }
    printf("%lld\n", a[N - 1][atcoder.length() - 1]);
    return 0;
}

