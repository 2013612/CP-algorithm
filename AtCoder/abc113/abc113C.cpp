#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;

struct pi {
	int P, Y;
}C[100006], D[100006];

bool f (pi x, pi y) {
	return x.P < y.P;
}

bool g (pi x, pi y) {
	return x.Y < y.Y;
}

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &C[i].P, &C[i].Y);
		D[i].P = C[i].P;
		D[i].Y = C[i].Y;
	}
	sort(C, C + M, f);
	vector<int> v, a;
	v.push_back(0);
	a.push_back(C[0].P);
	for (int i = 1; i < M; i++) {
		if (C[i].P != C[v.back()].P) {
			v.push_back(i);
			a.push_back(C[i].P);
		}
	}
	v.push_back(M);
	/*for (int i = 0 ; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;*/
	for (int i = 0; i + 1 < v.size(); i++) {
		sort(C + v[i], C + v[i + 1], g);
	}
	for (int i = 0; i < M; i++) {
		string temp;
		temp = to_string(D[i].P);
		while (temp.size() < 6) {
			temp.insert(0, "0");
		}
		string temp2;
		int temp3 = lower_bound(a.begin(), a.end(), D[i].P) - a.begin();
		int l = v[temp3];
		int r = v[temp3 + 1] - 1;
		while (l < r) {
			int mid = (l + r)/2;
			if (C[mid].Y < D[i].Y) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		//printf("%d %d\n", l, r);
		temp2 = to_string(r - v[temp3] + 1);
		while (temp2.size() < 6) {
			temp2.insert(0, "0");
		}
		string ans = temp + temp2;
		printf("%s\n", ans.c_str());
	}
	return 0;
}
