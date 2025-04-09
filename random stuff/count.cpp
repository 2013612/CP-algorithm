#include <iostream>

using namespace std;

int main()
{
    int count = 1;
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k < i && k <= j; k++) {
                printf("%d %d %d %d\n", count, i, k, j);
                count++;
            }
        }
    }

    return 0;
}
