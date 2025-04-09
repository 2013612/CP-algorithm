#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;

int n;
vector<int> b, c;
vector<bool> a;

void outputprime(int n){ // vector is used
	a.push_back(false);
	a.push_back(false);
	for(int i = 2; i <= n; i++){
		a.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (a[i] == false){
			continue;
		} else{
			for (int j = 2*i; j <= n; j+=i){
				a[j] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	outputprime(n);
	for (int j = 2; j <= n; j++) {
		int num = n;
		if (num % j == 0){
		    for (int i = j; ; ) {
    			if (num % i == 0) {
    				c.push_back(i);
    				b.push_back(0);
    				num /= i;
    				for (int k = 0; k < c.size(); k++) {
    					b.back() += c[k] - 1;
    				}
    				b.back() += num - 1;
    			} else {
    				i++;
			    }
			    if (num == 1 || i > num) {
			    	break;
			    }
		    }
		    c.clear();
		}
	}
	sort(b.begin(), b.end());
	for (int i = 1; i < b.size(); i++) {
		if (b[i] == b[i-1]) {
			b.erase(b.begin() + i);
			i--;
		}
	}
	printf("%d\n", b.size());
	for (int i = 0; i < b.size(); i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
