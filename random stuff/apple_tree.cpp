#include<iostream>
#include<vector>
using namespace std;

int main(){
	int length;
	cin >> length;
	vector<int> x,y;
	for (int i=0;i<length-1;i++){
		int tem;
		cin >> tem;
		y.push_back(tem);
		x.push_back(i+2);
	}
	int apple = 1;
	while (x.size()>0){
		bool erase = false;
		for (int i=0;i<x.size();i++){
			for (int j=i+1;j<x.size();j++){
				if (y[x[i]-2]==y[x[j]-2]){
					x.erase(x.begin()+i);
					x.erase(x.begin()+j-1);
					i--;
					erase = true;
					break;
				}
				erase = false;
			}
			if (!erase){
				x[i] = y[x[i]-2];
			}
			if (x[i] == 1){
				x.erase(x.begin()+i);
				apple++;
				i--;
			}
		}
		if (x.size()==1){
			apple++;
			break;
		}
	}
	cout << apple;
	return 0;
}
