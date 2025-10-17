#include<iostream>
using namespace std;

int n, a[20], b[20];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);

        if (a[i] > 0) {
            b[a[i]]++;            
        }
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] > 1) {
            printf("No\n");
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            for (int j = 1; j <= n; j++) {
                if (b[j] == 0) {
                    b[j]++;
                    a[i] = j;
                    break;
                }
            }
        }
    }

    printf("Yes\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}