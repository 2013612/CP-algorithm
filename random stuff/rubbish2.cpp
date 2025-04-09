#include<iostream>
#include<string>
using namespace std;

int T, a, b, N;
int main(){
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &a, &b, &N);
        a++;
        while(a < b) {
            int mid = (a + b)/2;
            cout << mid << endl;
            string s;
            cin >> s;
            if (s == "CORRECT" || s == "WRONG_ANSWER") {
                break;
            } else if (s == "TOO_SMALL") {
                a = mid;
            } else {
                b = mid;
            }
        }
    }
    return 0;
}
