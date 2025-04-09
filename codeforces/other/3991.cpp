#include<iostream>
using namespace std;

int n,a[1004];

struct Data{
	int value, x, y;
};

Data data[1000007], ans[1000007];
int main(){
	do {
		cin >> n;
		int k = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++){
			for (int j = i; j < n; j++){
				data[k].value = a[i] + a[j];
				data[k].x = a[i];
				data[++k].y = a[j];
			}
		}
		int m = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				ans[m].value = a[i] - a[j];
				ans[m].x = a[i];
				ans[++m].y = a[j];
			}
		}
		bool success = false;
		int max = -536870913;
		for (int i = 0; i < k; i++){
			for (int j = 0; j < m; j++){
				if (data[i].value == ans[j].value){
					if (data[i].x != ans[j].x && data[i].y != ans[j].x && data[i].x != ans[j].y && data[i].y != ans[j].y){
						if (ans[j].x > max){
							max = ans[j].x;
							success = true;
						}
					}
				}
			}
		}
		if (n != 0){
			if (!success && n != 0){
			cout << "no solution" << endl;
			} else {
			cout << max << endl;
		}
		}
	} while(n!=0);
	return 0;
}
