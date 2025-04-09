#include<iostream>
#include<math.h>
using namespace std;

int R, X, Y, x, y;
int main() {
	scanf("%d %d %d %d %d", &R, &X, &Y, &x, &y);
	long long dis1 = 1ll*(X - x)*(X - x) + 1ll*(Y - y)*(Y - y);
	//cout << X << " " << x << endl;
	//cout << dis1 << endl;
	double dis2 = sqrt(dis1);
	//cout << dis2 << endl;
	long long ans = ceil(dis2/(2 * R));
	printf("%lld\n", ans);
	return 0;
}
