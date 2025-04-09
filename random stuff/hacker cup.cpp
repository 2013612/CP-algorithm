#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("tourist.txt", "r", stdin);
	freopen("tourist_output.txt", "w", stdout);
	int campuses;
	cin >> campuses;
	string a[50];
	for (int i=0;i<campuses;i++){
		int att, visit;
		long long time;
		cin >> att >> visit >> time;
		for (int j=0;j<att;j++){
			cin >> a[j];
		}
		int x;
		x = ((time-1)*visit) % att;
		cout << "Case #" << i+1 << ": ";
		if (x+visit>att){
			for (int j=0;j<x+visit-att;j++){
				cout << a[j] << " ";
			}
			for (int j=x;j<att;j++){
				cout << a[j];
				if (j!=att-1){
					cout << " ";
				}
			}
		}
		else {
			for (int j=x;j<x+visit;j++){
				cout << a[j];
				if (j!=x+visit-1){
					cout << " ";
				}
			}
		}
		if (i!=campuses-1){
			cout << endl;
		}
	}
	return 0;
}
