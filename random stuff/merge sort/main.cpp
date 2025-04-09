#include <iostream>
using namespace std;

void sort(int x[], int n){
	if (n<=1){
		return;
	}
	else {
		int mid = n/2;
		sort(x,mid);
		sort(x+mid,n-mid);
	int z[n];
	int l = 0;
	int L = n/2;
	for (int a=0;a<n;a++){
		if (x[l]>=x[L]){
			z[a]=x[L];
			L++;
		}
		else {
			z[a]=x[l];
			l++;
		}
		if (l==mid){
			for (int b=L;b<n;b++){
				z[a+1]=x[b];
				a++;
			}
			break;
		}
		if (L==n){
			for (int b=l;b<mid;b++){
				z[a+1]=x[b];
				a++;
			}
			break;
		}
	}
	for (int c=0;c<n;c++){
		x[c] = z[c];
	}
	}
}

int main() {
	int n;
	cout <<"input the length of the array:";
	cin>>n;
	int x[n];
	cout <<"input the array:";
	for (int i=0;i<n;i++){
		cin >> x[i];
	}
	sort(x,n);
	cout << "sorted array:";
	for (int i=0;i<n;i++){
		if (i!=n-1)
		cout << x[i] << " ";
		else 
		cout << x[i];
	}
	return 0;
}
