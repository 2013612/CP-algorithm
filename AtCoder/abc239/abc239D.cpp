#include<iostream>
#include<vector>
using namespace std;

int a, b, c, d;
vector<bool> v;

void outputprime(int n){ // vector is used
	v.push_back(false);
	v.push_back(false);
	for(int i = 2; i <= n; i++){
		v.push_back(true);
	}
	for(int i = 2; i*i <= n; i++){
		if (v[i] == false){
			continue;
		} else{
			for (int j = 2*i; j <= n; j+=i){
				v[j] = false;
			}
		}
	}
}

int main() {
	outputprime(1000);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	for (int i = a; i <= b; i++) {
		for (int j = c; j <= d; j++) {
			if (v[i + j]) {
				break;
			}
			if (j == d) {
				printf("Takahashi\n");
				return 0;
			}
		}
	}
	printf("Aoki\n");
	return 0;
}
