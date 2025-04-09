#include<iostream>
#include<string>
using namespace std;

int speed[103], dir1[103], ans1, ans2;
string dir2[103];

int main() {
	int temp1, temp2;
	cin >> temp1 >> temp2;
	speed[0] = 0;
	speed[1] = 15;
	speed[2] = 93;
	speed[3] = 201;
	speed[4] = 327;
	speed[5] = 477;
	speed[6] = 645;
	speed[7] = 831;
	speed[8] = 1029;
	speed[9] = 1245;
	speed[10] = 1467;
	speed[11] = 1707;
	speed[12] = 1959;
	dir1[1] = 1125;
	dir1[2] = 3375;
	dir1[3] = 5625;
	dir1[4] = 7875;
	dir1[5] = 10125;
	dir1[6] = 12375;
	dir1[7] = 14625;
	dir1[8] = 16875;
	dir1[9] = 19125;
	dir1[10] = 21375;
	dir1[11] = 23625;
	dir1[12] = 25875;
	dir1[13] = 28125;
	dir1[14] = 30375;
	dir1[15] = 32625;
	dir1[16] = 34875;
	dir2[0] = "N";
	dir2[1] = "NNE";
	dir2[2] = "NE";
	dir2[3] = "ENE";
	dir2[4] = "E";
	dir2[5] = "ESE";
	dir2[6] = "SE";
	dir2[7] = "SSE";
	dir2[8] = "S";
	dir2[9] = "SSW";
	dir2[10] = "SW";
	dir2[11] = "WSW";
	dir2[12] = "W";
	dir2[13] = "WNW";
	dir2[14] = "NW";
	dir2[15] = "NNW";
	dir2[16] = "N";
	for (int i = 0; i < 17; i++) {
		if (10*temp1 >= dir1[i]) {
			ans1 = i;
		}
	}
	for (int i = 0; i < 13; i++) {
		if (temp2 >= speed[i]) {
			ans2 = i;
		}
	}
	if (ans2 == 0) {
		cout << "C 0" << endl;
	} else {
		cout << dir2[ans1] << " " << ans2 << endl;
	}
	return 0;
}
