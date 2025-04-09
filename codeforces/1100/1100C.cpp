#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;

const double PI = 3.14159265;
int N, R;
int main(){
	scanf("%d %d", &N, &R);
	double angle = PI/N;
	printf("%.8lf\n", R*sin(angle)/(1 - sin(angle)));
	return 0;
}
