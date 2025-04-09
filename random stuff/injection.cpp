#include<iostream>
#include<map>
#include<vector>
using namespace std;

int N, M;
long long ans;
map<int, vector<int>> a, b;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		a[temp].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		b[temp].push_back(i);
	}
	for (auto x:a) {
		int ind = x.first;
		if (x.second.size() > b[ind].size()) {
			cout << -1 << endl;
			return 0;
		}
	}
	/*for (auto x:a) {
		cout << x.first << " ";
		for (auto y:x.second) {
			cout << y << " ";
		}
		cout << endl;
	}
	for (auto x:b) {
		cout << x.first << " ";
		for (auto y:x.second) {
			cout << y << " ";
		}
		cout << endl;
	}*/
	for (auto x:a) {
		int ind = x.first;
		int temp = 0;
		int mapped[b[ind].size() + 10];
		for (int i = 0; i < b[ind].size() + 10; i++) {
			mapped[i] = -1;
		}
		for (int i = 0; i < x.second.size(); i++) {
			int pos = lower_bound(b[ind].begin(), b[ind].end(), x.second[i]) - b[ind].begin();
			//cout << pos << endl;
			if (pos >= 1 && mapped[pos - 1] == -1) {
				if (x.second[i] - b[ind][pos - 1] <= b[ind][pos] - x.second[i]) {
					mapped[pos - 1] = i;
					temp += x.second[i] - b[ind][pos - 1];
				} else {
					mapped[pos] = i;
					temp += b[ind][pos] - x.second[i];
				}
			} else {
				for (int j = pos; j < b[ind].size(); j++) {
					if (mapped[j] == -1) {
						pos = j;
						break;
					}
				}
				temp += abs(x.second[i] - b[ind][pos]);
				if (pos == i) {
					mapped[pos] = i;
				} else {
					int temp2 = 0;
					int pos2;
					for (int j = pos - 1; j >= 0; j--) {
						if (mapped[j] == -1) {
							pos2 = j;
							break;
						}
					}
					for (int j = 0; j < pos2; j++) {
						if (mapped[j] >= 0) {
							temp2 += abs(x.second[mapped[j]] - b[ind][j]);
						}
					}
					for (int j = pos2; j < pos - 1; j++) {
						temp2 += abs(x.second[mapped[j + 1]] - b[ind][j]);
					}
					//cout << temp2 << "!" << endl;
					temp2 += abs(x.second[i] - b[ind][pos - 1]);
					//cout << temp2 << "!" << endl;
					if (temp < temp2) {
						mapped[pos] = i;
					} else {
						temp = temp2;
						for (int j = pos2; j < pos - 1; j++) {
							mapped[j] = mapped[j + 1];
						}
						mapped[pos - 1] = i;
					}
				}
			}
			//cout << ind << " " << temp << endl;
		}
		/*cout << ind << " ";
		for (int j = 0; j < b[ind].size() + 10; j++) {
			cout << mapped[j] << " ";
		}
		cout << endl;
		cout << ind << " " << temp << endl;*/
		ans += temp;
	}
	cout << ans << endl;
	return 0;
} 
