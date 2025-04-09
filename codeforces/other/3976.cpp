#include<iostream>
#include<vector>

std::vector<bool> b;
void prime(int M){ // vector is used
	b.push_back(false);
	b.push_back(false);
	for(int i = 2; i*i <= M; i++){
		b.push_back(true);
	}
	for(int i = 2; i*i*i*i <= M; i++){
		if (b[i] == false){
			continue;
		} else{
			for (int j = 2*i; j*j <= M; j+=i){
				b[j] = false;
			}
		}
	}
}

bool isprime(int x){
	return b[x];
}

int outputprime(int N, int M){ // vector is used
	std::vector<bool> a;
	if (N == 1) a.push_back(false);
	else a.push_back(true);
	for(int i = N + 1; i <= M; i++){
		a.push_back(true);
	}
	for(int i = 2; i*i <= M; i++){
		if (isprime(i)){
			if (N%i == 0 && N != i){
				a[0] = false;
			}
			for (int j = N + (i - N%i); j <= M; j+=i){
				if (j == i){
					continue;
				}
				a[j-N] = false;
			}
		}
	}
	int num = 0;
	for(auto x : a){
		if (x){
			num++;
		}
	}
	return num;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	prime(b);
	printf("%d\n", outputprime(a,b));
	return 0;
}
