#include<iostream>
using namespace std;

int cases,n,m,a[100006];

bool pred(int mid){
	int temp = a[0]+ 2*mid; 
	int egg = 1;
	for (int i=0;i<m;i++){
		if (a[i]>temp){
			temp = a[i] +2*mid;
			egg++;
		}
	}
	if (egg>n){
		return false;
	}
	else {
		return true;
	}
}

int main(){
	 cin >> cases;
	 for (int i=0;i<cases;i++){
	 	cin >> n >> m;
	 	int l = 0, r = 1000000;
	 	for (int j=0;j<m;j++){
	 		cin >> a[j];
	 		a[j] *= 2;
	 	}
	 	while (l<=r){
	 		int mid = (l+r)/2;
	 		if (l==r) {
	 			break;
	 		}
	 		if (pred(mid)){
	 			r = mid;
	 		}
	 		else {
	 			l = mid +1;
	 		}
	 	}
	 	if (l%2==0){
	 		cout << l/2 << ".0" << endl;
	 	}
	 	else {
	 		cout << l/2 << ".5" << endl;
	 	}
	 }
	return 0;
}
