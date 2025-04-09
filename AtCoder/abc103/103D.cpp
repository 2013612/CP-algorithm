#include<iostream>
using namespace std;

int N, M, a[100006], b[100006];

void sort(int x[],int n, int y[]){
	if (n<=1){
		return;
	}
	int m ,z[n], k[n];
	m = rand()%n;
	int l =0, r=n-1;
	for (int i = 0;i<n;i++){
		if (x[i]>x[m] && i!=m){
			z[r] = x[i];
			k[r] = y[i];
			r--;
		}
		else if (x[i]<=x[m] && i!=m){
			z[l] = x[i];
			k[l] = y[i];
			l++;
		}
	}
	z[l] = x[m];
	k[l] = y[m];
	for (int i = 0;i<n;i++){
		x[i] = z[i];
		y[i] = k[i];
	}
	sort(x, l, y);
	sort(x+l, n-l, y+l);
}

int dekiru() {
	int br = 0;
	int p = 0;
	for (int i = 0; i < M; i++) {
		if (a[i] >= p) {
			br++;
			p = b[i];
		}
	}
	return br;
}

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	sort(b,M,a);
	/*for (int i = 0; i < M; i++) {
		cout << "@" << a[i] << " " << b[i] << endl;
	}*/
	for (int i = 0, j = 0; i < M; j++) {
		if (b[i] != b[j]) {
			sort(a + i, j-i, b + i);
			i = j;
		}
	}
	/*for (int i = 0; i < M; i++) {
		cout << "!" << a[i] << " " << b[i] << endl;
	}*/
	printf("%d\n", dekiru());
	return 0;
}
