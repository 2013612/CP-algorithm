#include<iostream>
using namespace std;

int main(){
	freopen("interception.txt", "r", stdin);
	freopen("interception_output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i=0;i<T;i++){
		int degree;
		cin >> degree;
		for (int j=0;j<degree+1;j++){
			int a[200];
			cin >> a[j];
		}
		if (degree%2==1){
			cout << "Case #" << i+1 << ": 1" << endl;
			cout << 0 << endl; 
		}
		else {
			cout << "Case #" << i+1 << ": 0" << endl;
		}
	}
	return 0;
}
