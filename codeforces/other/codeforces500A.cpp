#include<iostream>
#include<algorithm>
using namespace std;

int n,x,a[100006];
bool success0 = false;
bool success1 = false;
bool success2 = false;

int main(){
	cin >> n >> x;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i=0;i<n-1;i++){
		if (a[i]==a[i+1]){
			success0 = true;
			break;
		}
	}
	if (!success0){
		for (int i=0;i<n;i++){
			int temp = a[i];
			a[i] = a[i]&x;
			int temp2 = a[i];
			sort(a,a+n);
			int *p = find(a,a+n,temp2);
			if (p!= a && p!=a+n-1){
				if (*p==*(p-1)||*p==*(p+1)){
					success1 = true;
					break;
				}
			}
			else if (p==a){
				if (*p==*(p+1)){
					success1 = true;
					break;
				}
			}
			else if (p==a+n-1){
				if (*p==*(p-1)){
					success1 = true;
					break;
				}
			}
			*p = temp;
			sort(a,a+n);
		}
	}
	if (!success0 && !success1){
		for (int i=0;i<n;i++){
			a[i] = a[i]&x;
		}
		sort(a,a+n);
		for (int i=0;i<n-1;i++){
			if (a[i]==a[i+1]){
				success2 = true;
				break;
			}
		}
	}
	if (success0){
		cout << 0;
	}
	else if (success1){
		cout << 1;
	}
	else if (success2){
		cout << 2;
	}
	else {
		cout << -1;
	}
	return 0;
}
