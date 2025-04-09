#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int A, B, temp1, temp2;
bool C[100006];
int main(){
	scanf("%d %d", &A, &B);
	if (A > B) {
		temp1 = B;
		temp2 = A;
	} else {
		temp1 = A;
		temp2 = B;
	}
	int count = 1;
	vector<int> a;
	vector<int> b;
	int remainder = 0;
	while (temp1 > 0) {
		if (count > temp1) {
			a.push_back(count);
			C[count] = true;
			remainder = count - temp1;
			count++;
			break;
		}
		a.push_back(count);
		temp1 -= count;
		C[count] = true;
		count++;
	}
	if (remainder != 0) {
		b.push_back(remainder);
		temp2 -= remainder;
	}
	while (temp2 > 0) {
		if (C[count]) {
			count++;
		}
		if (count > temp2) {
			break;
		}
		b.push_back(count);
		temp2 -= count;
		C[count] = true;
		count++;
	}
	if (A > B) {
		printf("%d\n", b.size());
		for (int i = 0; i < b.size(); i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		if (remainder != 0) {
			printf("%d\n", a.size() - 1);
		} else {
			printf("%d\n", a.size());
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != remainder) {
				printf("%d ", a[i]);
			}
		}
	} else {
		if (remainder != 0) {
			printf("%d\n", a.size() - 1);
		} else {
			printf("%d\n", a.size());
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != remainder) {
				printf("%d ", a[i]);
			}
		}
		printf("\n");
		printf("%d\n", b.size());
		for (int i = 0; i < b.size(); i++) {
			printf("%d ", b[i]);
		}
	}
	return 0;
}
