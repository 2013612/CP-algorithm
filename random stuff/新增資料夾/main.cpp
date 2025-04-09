#include <iostream>
#include <string>
using namespace std;

void sort(int x[], int n){
	if (n<=1){
		return;
	}
	else {
		int mid = n/2;
		sort(x,mid);
		sort(x+mid,n-mid);
	int z[n];
	int l = 0;
	int L = n/2;
	for (int a=0;a<n;a++){
		if (x[l]>=x[L]){
			z[a]=x[L];
			L++;
		}
		else {
			z[a]=x[l];
			l++;
		}
		if (l==mid){
			for (int b=L;b<n;b++){
				z[a+1]=x[b];
				a++;
			}
			break;
		}
		if (L==n){
			for (int b=l;b<mid;b++){
				z[a+1]=x[b];
				a++;
			}
			break;
		}
	}
	for (int c=0;c<n;c++){
		x[c] = z[c];
	}
	}
}

int main() {
	int day, hour, skip;
	cin >> day >> hour >> skip;
	string y[day];
	int x[day][hour] ;
	int z[day*hour];
	for (int i=0;i<day;i++){
		cin >> y[i];
	}
	int k = 0;
	for (int i=0;i<day;i++){
		for (int j=0;j<hour;j++){
				x[i][j] = 0;
				z[k] = 0;
				k++;
		}
	}
	for (int i=0;i<day;i++){
		k = 0;
		for (int j=0;j<hour;j++){
			if (y[i][j] == '1'){
				x[i][k] = j+1;
				k++;
			}
		}
	}
	for (int i=0;i<day;i++){
		for (int j=0;j<hour;j++){
			cout << x[i][j]<<'c'<<endl;
		}
	}
	int total_hour = 0;
	k = 0;
	for (int i = 0;i<day;i++){
		for (int j=0;j<hour;j++){
			if (x[i][hour-j-1] != 0){
				total_hour = total_hour + (x[i][hour-j-1] - x[i][0] + 1);
				cout << total_hour << 'a'<<endl;
				break;
			}
		}
	}
	for (int i = 0;i<day;i++){
		for (int j = 0;j<hour;j++){
			if (j==hour-1 ){
				z[k] = y[i][j] - '0';
			}
			else {
				z[k] = x[i][j+1] - x[i][0];
			}
			k++;
		}
	}
	sort(z,k);
	for (int i = 0; i<k;i++){
		cout << z[i] << 'b'<<endl;
	}
	for (int i=0;i<skip;i++){
		total_hour = total_hour - z[k-i-1];
	}
	cout << total_hour;
	return 0;
}
