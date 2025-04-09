#include<iostream>
using namespace std;

int n;
int main(){
	while (scanf("%d", &n) != EOF) {
		int k = 1;
		for (int i=0;i<n;i++){
			k = k%n;
			if (k == 0){
				cout << i +1 << endl;
				break;
			}
			else {
				k = k*10 +1;
			}
		}
	}
	return 0;
}
