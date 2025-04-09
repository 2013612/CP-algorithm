#include<iostream>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	int k = -1;
	for (int i=a+1;i<b+1;i++){
		bool prime = true;
		for (int j=2;j*j<i+1 && j<a+1;j++){
			if (i%j==0){
				prime = false;
				break;
			}
		}
		if (prime){
			k = i;
		}
	}
	cout << k;
	return 0;
} 
