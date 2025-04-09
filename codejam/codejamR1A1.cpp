#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int T, N, ans;
string a[1004], suffix[1000007];
int main(){
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        ans = 0;
        for (int j = 0; j < N; j++) {
            cin >> a[j];
            reverse(a[j].begin(), a[j].end());
        }
        int cou = 0;
        for (int j = 0; j < N - 1; j++) {
        	for (int k = j + 1; k < N; k++) {
        		string temp;
        		for (int l = 0; l < min(a[j].length(), a[k].length()); l++) {
        			if (a[j][l] == a[k][l]) {
        				temp.push_back(a[j][l]);
        			} else {
        				break;
        			}
        		}
        		suffix[cou] = temp;
        		cou++;
        	}
        }
        sort(suffix, suffix + cou);
        ans = 2*cou;
        for (int j = 0; j < cou - 1; j++) {
        	if (suffix[j] == suffix[j + 1]) {
        		ans -= 2;
        	}
        }
        if (suffix[0] == suffix[N - 1]) {
        	ans -= 2;
        }
        if (ans == 0 && suffix[0] != "") {
        	ans += 2;
        }
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}
