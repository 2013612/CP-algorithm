#include <iostream>
using namespace std;

int main() {
	int n,sum;
	sum = 0;
	cin >> n;
	int x[n];
	for (int i=0;i<n;i++){
		cin >> x[i];
	}
	for (int i=0;i<n;i++){
		if (x[i]>=0){
			sum = sum + x[i];
		}
		else {
			sum = sum - x[i];
		}
	}
	cout << sum;
	return 0;
}
