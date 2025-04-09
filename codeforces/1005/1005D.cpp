#include<iostream>
#include<string>
using namespace std;

int a[1000007];
string n;
int main(){
	cin >> n;
	for (int i = 0; i < n.length(); i++){
		a[i] = n[i] - '0';
	}
	int num = 0;
	int k = n.length();
	for (int i = 0; i < k; i++) {
		if (a[i] % 3 == 0) {
			num++;
		} else if (i < k - 1 && (a[i+1] % 3 == 0 || (a[i] + a[i+1]) % 3 == 0)) {
			num++;
			i++;
		} else if (i < k - 2 && (a[i+2] % 3 == 0 || (a[i] + a[i+1] + a[i+2]) % 3 == 0)) {
			num++;
			i+=2;
		}
	}
	printf("%d\n", num);
	return 0;
}
