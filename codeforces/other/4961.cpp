#include<iostream>
#include<algorithm>
using namespace std;

int N;
int a[100006];
int main(){
	cin >> N;
	int n =N;
	for (int i=0;i<N;i++){
		cin >> a[i];
	}
	sort(a,a+N);
	for (int i=0;i<N-1;i++){
		if (a[i] == a[i+1]){
			n--;
		}
	}
	cout << n;
	return 0;
}
