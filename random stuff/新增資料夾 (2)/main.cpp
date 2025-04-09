#include <iostream>
#include <math.h> 
using namespace std;


int main() {
	int n,a,b;
	cin >> n >> a >> b;
	int turn;
	turn = log2(n);
	int t = 1;
	while (turn>0){
		if ((a+1)/2 == (b+1)/2){
			break;
		}
		else {
			a = (a+1)/2;
			b = (b+1)/2;
			t++;
		}
	}
	if (t==turn){
		cout << "Final!";
	}
	else {
		cout << t;
	}
	return 0;
}
