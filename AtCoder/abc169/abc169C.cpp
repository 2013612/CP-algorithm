#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

long long A;
string B;
int main() {
	cin >> A >> B;
	long long temp = (B[0] - '0')*100 + (B[2] - '0')*10 + (B[3] - '0');
	cout << A*temp/100 << endl;
	return 0;
}
