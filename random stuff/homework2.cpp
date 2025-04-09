#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	int n,b,sum;
	sum = 0;
	cin >> n;
	vector<int> a;
	for (int i=0;i<n;i++){
		cin>>b;
		a.push_back(b);
	}
	for (int i=0;i<n;i++){
		sum = sum +a[i];
	}
	cout << sum << endl;
	sort (a.begin(),a.end());
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	
	return 0;
}
