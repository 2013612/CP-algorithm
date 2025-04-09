#include <iostream>
#include <stdlib.h>
using namespace std;

void sort(int x[],int n){
	if (n<=1){
		return;
	}
	int m ,z[n];
	m = rand()%n;
	int l =0, r=n-1;
	for (int i = 0;i<n;i++){
		if (x[i]>x[m] && i!=m){
			z[r] = x[i];
			r--;
		}
		else if (x[i]<=x[m] && i!=m){
			z[l] = x[i];
			l++;
		}
	}
	z[l] = x[m];
	for (int i = 0;i<n;i++){
		x[i] = z[i];
	}
	sort(x,l);
	sort(x+l,n-l);
}

int main() {
	int n;
	cout << "type the size of the array:";
	cin >> n;
	int x[n];
	cout << "type the array:";
	for (int i=0;i<n;i++){
		cin >> x[i];
	}
	sort (x,n);
	for (int i = 0;i<n;i++){
		if (i!=n){
			cout << x[i] << " ";
		}
		else {
			cout << x[i];
		}
	}

	return 0;
}
