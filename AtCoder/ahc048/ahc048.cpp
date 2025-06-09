#include<bits/stdc++.h>
using namespace std;

int n, k, h, t, d;
vector<double> origin[30], target[1004], average;
vector<vector<bool>> v_door, h_door;
unordered_map<string, vector<double>> combin[20];
unordered_map<string, vector<double>> combin2[20];

long double dis(vector<double> target, vector<double> paint) {
	long double sum = 0;
	for (int i = 0; i < 3; i++) {
		long double t = target[i] - paint[i];
		t = t * t;
		sum += t;
	}
	
	return sqrt(sum);
}

struct Step {
	string command;
	long double error;
	
	Step(string command, long double error) : command(command), error(error) {
	}
	
	Step(string command) : command(command), error(0) {
	}
};

struct Steps {
	vector<Step> steps;
	int step1_cnt = 0;
	int step2_cnt = 0;
	long double error_sum = 0;
	
	void step1(int i, int j, int k) {
		string c = "1 " + to_string(i) + " " + to_string(j) + " " + to_string(k);
		steps.push_back(Step(c));
		step1_cnt++;
	}
	
	void step2(int i, int j, long double error) {
		string c = "2 " + to_string(i) + " " + to_string(j);
		steps.push_back(Step(c, error));
		step2_cnt++;
		error_sum += error;
	}
	
	void step3(int i, int j) {
		string c = "3 " + to_string(i) + " " + to_string(j);
		steps.push_back(Step(c));
	}
	
	void step4(int i, int j, int i2, int j2) {
		string c = "4 " + to_string(i) + " " + to_string(j) + " " + to_string(i2) + " " + to_string(j2);
		steps.push_back(Step(c));
	}
	
	long long cal_score() {
		return 1 + 1ll * d * (step1_cnt - step2_cnt) + round(10000 * error_sum);
	}
};

struct Well {
	vector<pair<int, int>> cell;
	vector<double> ratio = vector<double>(3, 0);
	int gram = 0;
	vector<pair<pair<int, int>, pair<int, int>>> doors;
	
	Well(int i, int j) {
		cell.push_back({i, j});
	}
	
	void link(Well other, pair<pair<int, int>, pair<int, int>> door) {
		for (auto x: other.cell) {
			cell.push_back(x);
		}
		
		for (int i = 0; i < 3; i++) {
			ratio[i] = (ratio[i] * gram + other.ratio[i] * other.gram) / (gram + other.gram);	
		}
		
		gram += other.gram;
		
		doors.push_back(door);
	}
	
	void add_paint(vector<double> paint) {
		for (int i = 0; i < 3; i++) {
			ratio[i] = (ratio[i] * gram + paint[i]) / (gram + 1);	
		}
		
		gram++;
	}
};

struct Palette {
	int size;
	vector<vector<Well>> empty_wells;
	vector<vector<Well>> non_empty_wells;
	Steps steps = Steps();
	
	Palette(int size): size(size) {
		empty_wells.resize(size);
		non_empty_wells.resize(size);
		
		empty_wells[1].push_back(Well(0, 0));
		empty_wells[1].push_back(Well(0, 1));
		
		for (int i = 2; i < size; i += 3) {
			Well x = Well(0, i);
			x.link(Well(0, i + 1), {{0, i}, {0, i + 1}});
			x.link(Well(0, i + 2), {{0, i + 1}, {0, i + 2}});
			empty_wells[3].push_back(x);
		}
		
		for (int j = 1; j <= 2; j++) {
			for (int i = 0; i < size; i += 2) {
				Well x = Well(j, i);
				x.link(Well(j, i + 1), {{j, i}, {j, i + 1}});
				empty_wells[2].push_back(x);
			}
		}
		
		for (int i = 0; i < size; i++) {
			Well x = Well(3, i);
			x.link(Well(4, i), {{3, i}, {4, i}});
			x.link(Well(5, i), {{4, i}, {5, i}});
			empty_wells[3].push_back(x);
		}
		
		for (int i = 6; i < 12; i++) {
			for (int j = 0; j < size; j += 4) {
				Well x = Well(i, j);
				for (int k = 1; k <= 3; k++) {
					x.link(Well(i, j + k), {{i, j + k - 1}, {i, j + k}});
				}
				
				empty_wells[4].push_back(x);
			}
		}
		
		for (int i = 12; i < 15; i++) {
			for (int j = 0; j < size; j += 5) {
				Well x = Well(i, j);
				for (int k = 1; k <= 4; k++) {
					x.link(Well(i, j + k), {{i, j + k - 1}, {i, j + k}});
				}
				
				empty_wells[5].push_back(x);
			}
		}
		
		for (int i = 6; i <= 10; i++) {
			Well x = Well(9 + i, 0);
			for (int j = 1; j <= i - 1; j++) {
				x.link(Well(9 + i, j), {{9 + i, j - 1}, {9 + i, j}});
			}
			
			empty_wells[i].push_back(x);
		}
	}
	
	void take_from_well(int x, int y, long double e) {
		auto cell = non_empty_wells[x][y].cell[0];
		steps.step2(cell.first, cell.second, e);
		
		non_empty_wells[x][y].gram--;
		
		if (non_empty_wells[x][y].gram == 0) {
			empty_wells[x].push_back(non_empty_wells[x][y]);
			non_empty_wells[x].erase(non_empty_wells[x].begin() + y);
		}
	}
	
	void take_from_last_well(int x, long double e) {
		int size = non_empty_wells[x].size();
		take_from_well(x, size - 1, e);
	}
	
	void add_to_well(string s, int cnt) {
		Well well = empty_wells[cnt].back();
		empty_wells[cnt].pop_back();
		for (int i = 0; i < s.size(); i++) {
			for (char j = '0'; j < s[i]; j++) {
				well.add_paint(origin[i]);
				
				steps.step1(well.cell[0].first, well.cell[0].second, i);
			}
		}
		
		non_empty_wells[cnt].push_back(well);
	}
	
	void add_to_well(int ind) {
		Well well = empty_wells[1].back();
		well.add_paint(origin[ind]);
		non_empty_wells[1].push_back(well);
		steps.step1(well.cell[0].first, well.cell[0].second, ind);
	}
	
	pair<int, int> nearest_in_wells(vector<double> &tar) {
		long double min_error_1 = 1e9;
			
		int x = -1, y = -1;
		for (int j = 0; j < non_empty_wells.size(); j++) {
			for (int k = 0; k < non_empty_wells[j].size(); k++) {
				long double d = dis(tar, non_empty_wells[j][k].ratio);
				
				if (d < min_error_1) {
					x = j;
					y = k;
					min_error_1 = d;
				}
			}
		}
		
		return {x, y};
	}
	
	vector<double> new_ratio_with_extra(int j, int k, int i) {
		Well well = non_empty_wells[j][k];
		vector<double> new_ratio = well.ratio;
		int gram = well.gram;
		
		for (int p = 0; p < 3; p++) {
			new_ratio[p] = origin[i][p] + new_ratio[p] * gram;
			new_ratio[p] /= (gram + 1);
		}
		
		return new_ratio;
	}
	
	pair<pair<int, int>, int> nearest_in_wells_extra(vector<double> &tar) {
		long double min_error_1 = 1e9;
			
		int x = -1, y = -1, z = -1;
		for (int i = 0; i < non_empty_wells.size(); i++) {
			for (int j = 0; j < non_empty_wells[j].size(); j++) {
				long double d = dis(tar, non_empty_wells[i][j].ratio);
				if (d < min_error_1) {
					x = i;
					y = j;
					z = -1;
					min_error_1 = d;
				}
				
				for (int p = 0; p < k; p++) {
					vector<double> new_ratio = new_ratio_with_extra(i, j, p);
					
					long double d2 = dis(tar, new_ratio);
				
					if (d2 < min_error_1) {
						x = i;
						y = j;
						z = p;
						min_error_1 = d;
					}
				}
			}
		}
		
		return {{x, y}, z};
	}
	
	void take_nearest(vector<double> &tar) {
		auto [temp, z] = nearest_in_wells_extra(tar);
		auto [x, y] = temp;
		long double min_error_1 = 1e5;
		if (x >= 0) {
			vector<double> ratio = non_empty_wells[x][y].ratio;
			
			if (z >= 0) {
				ratio = new_ratio_with_extra(x, y, z);
			}
			
			min_error_1 = dis(tar,  non_empty_wells[x][y].ratio);
		}
		
		string s = "";
		int cnt = 0;
		long double min_error_2 = 1e5;
		
		for (int i = 1; i <= 5; i++) {
			if (empty_wells[i].empty()) {
				continue;
			}
			
			for (auto [str, ratio]: combin[i]) {
				long double d = dis(tar, ratio);
				
				if (d < min_error_2) {
					s = str;
					cnt = i;
					min_error_2 = d;
				}
			}
		}
		
		if (min_error_1 < min_error_2) {
			if (z >= 0) {
				add_to_well(z);
			}
			
			take_from_well(x, y, min_error_1);
		} else {
			add_to_well(s, cnt);
			take_from_last_well(cnt, min_error_2);
		}
	}
	
	bool has_many_paint() {
		int extra = steps.step1_cnt - steps.step2_cnt;
		int left = h - steps.step2_cnt;
		
		return extra * 2 >= left;
	}
	
	void take_nearest_from_well(vector<double> &tar) {
		auto [x, y] = nearest_in_wells(tar);
		
		if (x >= 0) {
			take_from_well(x, y, dis(tar, non_empty_wells[x][y].ratio));
		} else {
			long double min_error = dis(tar, origin[0]);
			int ind = 0;
			for (int i = 1; i < k; i++) {
				long double d = dis(tar, origin[i]);
				
				if (d < min_error) {
					ind = i;
					min_error = d;
				}
			}
			
			add_to_well(ind);
			take_from_last_well(1, min_error);
		}
	}
	
	void naive_solve(int start) {
		for (int i = start; i < h; i++) {
			long double min_error_1 = 1e9;
			
			int x = -1, y = -1;
			for (int j = 0; j < non_empty_wells.size(); j++) {
				for (int k = 0; k < non_empty_wells[j].size(); k++) {
					long double d = dis(target[i], non_empty_wells[j][k].ratio);
					
					if (d < min_error_1) {
						x = j;
						y = k;
						min_error_1 = d;
					}
				}
			}
			
			int ind = 0;
			long double min_error_2 = 1e9;
			for (int j = 0; j < k; j++) {
				long double d = dis(target[i], origin[j]);
				
				if (d < min_error_2) {
					min_error_2 = d;
					ind = j;
				}
			}
			
			if ((min_error_1 - min_error_2) * 1e4 <= d) {
				take_from_well(x, y, min_error_1);
			} else {
				add_to_well(ind);
				take_from_last_well(1, min_error_2);
			}
		}
	}

	int average_solve(int start, int length) {
		average = vector<double>(3, 0);
		for (int i = start; i < start + length; i++) {
			for (int j = 0; j < 3; j++) {
				average[j] += target[i][j];
			}
		}
		
		for (int j = 0; j < 3; j++) {
			average[j] /= length;
		}
		
		int cnt = 0;
		string s;
		vector<double> ratio;
		long double min_e = 1e9;
		for (int i = 1; i <= min(10, length); i++) {
			for (auto [x, y]: combin2[i]) {
				long double d = dis(y, average);
				
				if (d < min_e) {
					min_e = d;
					s = x;
					ratio = y;
					cnt = i;
				}
			}
		}
		
//		printf("! %d\n", cnt);
		
		for (int i = start; i < start + length / cnt * cnt; i++) {
			if ((i - start) % cnt == 0) {
				add_to_well(s, cnt);
			}
			
			long double e = dis(ratio, target[i]);
			take_from_last_well(cnt, e);
		}
		
//		printf("!!\n");
		
//		for (int i = start + length / cnt * cnt; i < start + length; i++) {
//			int ind = 0;
//			long double e = 1e9;
//			for (int j = 0; j < k; j++) {
//				long double d = dis(target[i], origin[j]);
//				
//				if (d < e) {
//					e = d;
//					ind = j;
//				}
//			}
//			
//			add_to_well(ind);
//			take_from_last_well(1, e);
//		}

		return start + length / cnt * cnt;
	}
};

void read_input() {
	scanf("%d %d %d %d %d", &n, &k, &h, &t, &d);
	for (int i = 0; i < k; i++) {
		origin[i].resize(3);
		cin >> origin[i][0] >> origin[i][1] >> origin[i][2];
	}
	
	for (int i = 0; i < h; i++) {
		target[i].resize(3);
		cin >> target[i][0] >> target[i][1] >> target[i][2];
	}
}

void precompute(string s, vector<double> ratio, int cnt) {
//	if (s.size() == k) {
//		if (cnt > 0) {
//			vector<double> v = ratio;
//			for (int i = 0; i < 3; i++) {
//				ratio[i] = ratio[i] / cnt;
//			}
//			
//			combin[cnt][s] = v;
//		}
//		
//		return;
//	}
//	
//	precompute(s + '0', ratio, cnt);
//	
//	if (cnt < 5) {
//		vector<double> v = ratio;
//		for (int i = 0; i < 3; i++) {
//			v[i] += origin[s.size()][i];
//		}
//		
//		precompute(s + '1', v, cnt + 1);
//	}
	
//	for (int i = 0; i < k; i++) {
//		vector<int> v(20, 0);
//		v[i] = 1;
//		combin2[1][v] = origin[i];
//	}
	
	int c = 0;
	int max = 3e5;
	combin2[0][string(k, '0')] = vector<double>(3, 0);
	for (int i = 0; i < 10 && c < max; i++) {
//		printf("!! %d\n", i);
		for (auto [x, y]: combin2[i]) {
//			cout << x << endl;
			for (int j = 0; j < k; j++) {
				string s = x;
				s[j] = s[j] + 1;
				vector<double> new_ratio = y;
				for (int p = 0; p < 3; p++) {
					new_ratio[p] *= i;
					new_ratio[p] += origin[j][p];
					new_ratio[p] /= (i + 1);
				}
				
				combin2[i + 1][s] = new_ratio;
				
//				cout << j << " " << s << endl;
				c++;
			}
			
			if (c > max) {
				break;
			}
		}
		
//		printf("!! %d %d\n", i + 1, combin2[i + 1].size());
	}
}

void init_door_setup() {
	int size = n;
	for (int i = 0; i < size; i++) {
		v_door.push_back(vector<bool>(size, false));
		h_door.push_back(vector<bool>(size, false));
	}
	
	for (int i = 2; i < size; i += 3) {
		v_door[0][i] = v_door[0][i + 1] = true;
	}
	
	for (int j = 1; j <= 2; j++) {
		for (int i = 0; i < size; i += 2) {
			v_door[j][i] = true;
		}
	}
	
	for (int i = 0; i < size; i++) {
		h_door[3][i] = h_door[4][i] = true;
	}
	
	for (int i = 6; i < 12; i++) {
		for (int j = 0; j < size; j += 4) {
			for (int k = 1; k <= 3; k++) {
				v_door[i][j + k - 1] = true;
			}
		}
	}
	
	for (int i = 12; i < 15; i++) {
		for (int j = 0; j < size; j += 5) {
			for (int k = 1; k <= 4; k++) {
				v_door[i][j + k - 1] = true;
			}
		}
	}
	
	for (int i = 6; i <= 10; i++) {
		for (int j = 1; j <= i - 1; j++) {
			v_door[9 + i][j - 1] = true;
		}
	}
}

void print_doors() {
	int size = n;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			printf("%d ", v_door[i][j] ? 1 : 0);
		}
		printf("\n");
	}
	
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", h_door[i][j] ? 1 : 0);
		}
		printf("\n");
	}
}

void init() {
	read_input();
	init_door_setup();
	print_doors();
	precompute("", vector<double>(3, 0), 0);
}

Steps simple_solve() {
	Palette pal = Palette(n);
	
	Steps steps;
	long long min_score = 4e18;
	
//	for (int i = 0; i < h - 50; i++) {
////		if (i % 25 == 0) {
////			Palette temp = pal;
////			temp.naive_solve(i);
////			long long temp_score = temp.steps.cal_score();
////			
////			if (temp_score < min_score) {
////				min_score = temp_score;
////				steps = temp.steps;
////			}
////			
//////			printf("!! %d %d %lld\n", i, steps.size(), temp_score);
////		}
//
//		if (pal.has_many_paint()) {
//			pal.take_nearest_from_well(target[i]);
//		} else {
//			pal.take_nearest(target[i]);
//		}
//	}
//	
//	pal.naive_solve(h - 50);
	int len = 10;

	for (int i = 0; i < h; ) {
		i = pal.average_solve(i, min(len, h - i));
	}
	steps = pal.steps;
	
//	printf("!!! %lld %lld\n", pal.cal_score(), min_score);
//	if (pal.steps.cal_score() < min_score) {
//		steps = pal.steps;
//	}
	
	return steps; 
}

int main() {
	init();
	
	for (auto step: simple_solve().steps) {
		cout << step.command << endl;
	}
	
	return 0;
}