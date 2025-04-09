#include <iostream>
using namespace std;

int A, B, C, X, Y;
int main()
{
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    printf("%d\n", min(A * X + B * Y, min(2 * X * C + max(Y - X, 0) * B, max(X - Y, 0) * A + 2 * Y * C)));
    return 0;
}

