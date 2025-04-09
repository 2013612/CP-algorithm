#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> m;
int main(){
	int n,sid;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> sid;
		if (m[sid] == 0){
			cout << "in" << endl;
			m[sid] = 1;
		}
		else {
			cout << "out" << endl;
			m[sid] = 0;
		}
	}
	return 0;
}
