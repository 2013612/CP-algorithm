#include<iostream>
#include<unordered_set>
using namespace std;

int n, a[400006];
long long s;
unordered_set<long long> us;

int main() {
	scanf("%d %lld", &n, &s);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[n + i] = a[i];
		sum += a[i];
	}
	
	long long re = s % sum;
	
	us.insert(0);
	long long t = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (us.count(t - re)) {
			printf("Yes\n");
			return 0;
		}
		
		t += a[i];
		us.insert(t);
	}
	
	printf("No\n");
	
	return 0;
}