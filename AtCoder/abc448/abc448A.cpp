#include<iostream>
using namespace std;

int n, x;
int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a < x) {
            x = a;
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}