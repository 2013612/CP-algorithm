#include<bits/stdc++.h>
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    int a, b;

    if (x == "Ocelot") {
        a = 1;
    } else if (x == "Serval") {
        a = 2;
    } else {
        a = 3;
    }

    if (y == "Ocelot") {
        b = 1;
    } else if (y == "Serval") {
        b = 2;
    } else {
        b = 3;
    }

    if (a >= b) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}