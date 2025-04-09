#include <iostream>
#include <deque>

using namespace std;

int N, K;
string S, ans;
deque<char> d;
int main()
{
    scanf("%d %d", &N, &K);
    cin >> S;
    for (int i = 0; i < N; i++) {
        while (!d.empty() && d.back() > S[i]) {
            d.pop_back();
        }
        d.push_back(S[i]);
        if (i >= N - K) {
            ans.push_back(d.front());
            d.pop_front();
        }
    }
    cout << ans << endl;
    return 0;
}

