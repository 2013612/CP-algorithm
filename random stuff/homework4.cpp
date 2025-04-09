#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int main(){
	map<string,int> m;
	map<string,bool> M;
	int n,val;
	cin >> n;
	string a,b;
	for (int i =0; i<n ;i++){
		cin >> a >> b;
		if (a == "insert"){
			cin >> m[b];
			M[b] = true;
		}
		else {
			if (m[b] == 0 && M[b] == false){
				cout << b << " not found";
			}
			else {
				cout << m[b];
			}
		}
	}
	return 0;
}
