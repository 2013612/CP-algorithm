#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

long long A, B, ans;
int main(){
	scanf("%lld %lld", &A, &B);
	printf("%lld\n", A*(A-1)/2 + B*(B-1)/2);
	return 0;
}
