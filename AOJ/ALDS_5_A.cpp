#include<iostream>
#include<unordered_set>
using namespace std;

int N, Q, a[103];
unordered_set<int> s;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << N); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        s.insert(sum);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int temp;
        scanf("%d", &temp);
        if (s.count(temp)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}

