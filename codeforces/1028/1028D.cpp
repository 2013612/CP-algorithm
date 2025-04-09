#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MOD = 1000000007;

int f(int m) {
	return m % MOD;
}

int abs(int m) {
	return m >= 0 ? m : -m;
}

int N, a[400006];
char temp[10], s[400006];
vector<int> book;
vector<int>::iterator k;
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
    	scanf("%s %d", temp, &a[i]);
    	s[i] = temp[1];
    	if (i != 0) {
    		k = lower_bound(book.begin(), book.end(), a[i]);
    	}
    	if (s[i] == 'D') {
    		if (i == 0) {
    			book.push_back(a[i]);
    		} else {
    			book.insert(k, a[i]);
    		}
    	} else {
    		book.erase(k);
    	}
    }
    int ans = 1;
    int pos = -1;
    for (int i = N - 1; i >= 0; i--) {
    	k = lower_bound(book.begin(), book.end(), a[i]);
    	if (s[i] == 'C') {
    		if (pos != -1) {
    			if (book.size() != 0 && pos - (k - book.begin() - 1) > 1) {
    				ans = 0;
    				break;
    			}
    		}
    		book.insert(k, a[i]);
    		pos = k - book.begin() + 1;
    		ans = f(ans*2);
    	} else {
    		book.erase(k);
    	}
    }
    for (int i = N - 1; i >= 0; i--) {
    	if (s[i] == 'D') {
    		ans = f(ans*2);
    	} else {
    		break;
    	}
    }
    printf("%d\n", ans);
    return 0;
}
