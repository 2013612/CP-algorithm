#include<iostream>
#include<set>
#include<utility>
using namespace std;
typedef pair<int, int> pii;

int N, M;
pii fix;
set<pii> stel, star;

int main()
{
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        pii temp;
        scanf("%d %d", &temp.first, &temp.second);
        stel.insert(temp);
        fix = temp;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        pii temp;
        scanf("%d %d", &temp.first, &temp.second);
        star.insert(temp);
    }
    for (auto p:star) {
        int x = p.first - fix.first;
        int y = p.second - fix.second;
        bool pass = true;
        for (auto q:stel) {
            if (star.count({q.first + x, q.second + y}) == 0) {
                pass = false;
                break;
            }
        }
        if (pass) {
            printf("%d %d\n", x, y);
            break;
        }
    }
    return 0;
}

