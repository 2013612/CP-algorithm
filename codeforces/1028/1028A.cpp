#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, M, r[2], c[2];
char A[200];
string S[200];
bool a;
bool b;
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
    	scanf("%s", A);
    	S[i] = A;
    }
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < M; j++) {
    		if (!a && S[i][j] == 'B') {
    			r[0] = i;
    			c[0] = j;
    			a = true;
    		}
    		if (a && S[i][j] == 'W') {
    			r[1] = i;
    			c[1] = j - 1;
    			b = true;
    		}
    		if (a && !b && j == M - 1) {
    			r[1] = i;
    			c[1] = j;
    		}
    		if (b) {
    			break;
    		}
    	}
    	if (a) {
    		break;
    	}
    }
    int k = c[1] - c[0] + 1;
    printf("%d %d\n", r[0] + k/2 + 1, c[0] + k/2 + 1);
    return 0;
}
