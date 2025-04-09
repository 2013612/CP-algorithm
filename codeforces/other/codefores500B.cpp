#include<iostream>
#include<algorithm>
using namespace std;

int n,a[1000007];

int main(){
	cin >> n;
	for (int i=0;i<2*n;i++){
		cin >> a[i];
	}
	sort(a,a+2*n);
	int num = 0;
	int k = 1;
	for (int i=0;i<2*n-1;i++){
		if (a[i] == a[i+1]){
			k++;
		}
		else {
			k = 1;
		}
		if (k>num){
			num = k;
		}
	}
	if (num >= n){
		cout << 0;
	}
	else {
		cout << ((a[n-1]-a[0])*(a[2*n-1]-a[n]));
	}
	return 0;
}
