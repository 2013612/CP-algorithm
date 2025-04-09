#include<iostream>
#include<stdlib.h>
using namespace std;

#ifndef ONLINE_JUDGE

long long ans, q = 0;
long long find();

bool query(int x) {
    q++;
    return ans < x;
}

int main() {
    cin >> ans;
    long long guess = find();
    if (q > 32) {
        cout << "Too many questions!" << endl;
    } else if (ans != guess) {
        cout << "Wrong answer!" << endl;
    } else {
        cout << "Congrats! You get the correct answer." << endl;
    }
    return 0;
}

#endif

int find() {
	long long k_after = 1;
	for (int i=0;i<31;i++) k_after*=2;
	long long k_before = k_after*2;
    for (int i =0;i<30;i++){
    	if (query(k_after)){
    		long long temp;
    		temp = k_after;
    		k_after -= abs(k_after - k_before)/2;
    		k_before = temp;
    	}
    	else {
    		long long temp;
    		temp = k_after;
    		k_after += abs(k_after - k_before)/2;
    		k_before = temp;
    	}
    }
    if (k_after>k_before){
    	if (query(k_after)){
    		return k_after-1;
    	}
    	else {
    		return k_after;
    	}
    }
    else {
    	if (query(k_before)){
    		return k_before-1;
    	}
    	else {
    		return k_before;
    	}
    }
}
