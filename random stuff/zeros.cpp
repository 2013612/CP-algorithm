#include<iostream>

long long n;

inline long long digits(long long x){
	long long digit = 0;
	long long k = 5;
	while(x >= k){
		digit += x/k; 
		k *= 5;
	}
	return digit;
}

inline long long binary_search(long long l, long long r, long long n){
	long long mid = (l + r)/2;
	if (l >= r){
		return mid;
	}
	if (digits(mid) > n){
		return binary_search(l, mid-1, n);
	} else if (digits(mid) < n){
		return binary_search(mid+1 , r, n);
	} else {
		return mid;
	}
}

int main(){
	scanf("%lld", &n);
	long long mid = binary_search(1, 9*n, n);
	if (digits(mid) != n){
		printf("Impossible\n");
	} else {
		printf("%lld\n", mid - mid%5);
	}
	return 0;
}

