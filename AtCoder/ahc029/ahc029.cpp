#include<iostream>
#include<vector>
using namespace std;

const int MAX_INVEST_COST = 500;

int n, m, k, t, cur_money;
vector<pair<int, int>> card[5];
pair<int, int> proj[100];
int cnt = 0;

int use_card() {
	// card_type, card_pos, card_target
	pair<pair<int, int>, int> result = {{0, 0}, -1};
	for (int i = 0; i < card[0].size(); i++) {
		int pos = -1;
		int work = card[0][i].first;
		for (int j = 0; j < m; j++) {
			int new_work = proj[j].first;
			int new_val = proj[j].second;
			if (work >= new_work) {
				if (pos == -1) {
					pos = j;
					continue;
				}
				int old_work = proj[pos].first;
				int old_val = proj[pos].second;
				
				if (new_val > old_val || (new_val == old_val && new_work > old_work)) {
					pos = j;
				}
			}
		}
		
		if (result.second == -1) {
			result = {{0, i}, pos};
			continue;
		}
		int result_val = proj[result.second].second;
		int result_work = card[0][result.first.second].first;
		int new_val = proj[pos].second;
		if (new_val > result_val || (new_val == result_val && work < result_work)) {
			result = {{0, i}, pos};
		}
	}
	
	if (card[0].size() > 0 && result.second == -1) {
		int pos = 0;
		for (int i = 0; i < card[0].size(); i++) {
			if (card[0][i].first > card[0][pos].first) {
				pos = i;
			}
		}
		result = {{0, pos}, 0};
		pos = 0;
		for (int i = 1; i < m; i++) {
			if (proj[i].first < proj[pos].first) {
				pos = i;
			}
		}
		result.second = pos;
	}
	
	for (int i = 0; i < card[1].size(); i++) {
		int sum = 0;
		int work = card[1][i].first;
		for (int j = 0; j < m; j++) {
			if (work >= proj[j].first) {
				sum += proj[j].second;
			}
		}
		
		if (result.second == -1 || sum >= proj[result.second].second) {
			result = {{1, i}, -2};
		}
	}
	
	if (card[1].size() > 0 && result.second == -1) {
		int pos = 0;
		for (int i = 0; i < card[1].size(); i++) {
			if (card[1][i].first > card[1][pos].first) {
				pos = i;
			}
		}
		result = {{1, pos}, -2};
	}
	
	if (!card[4].empty()) {
		result = {{4, 0}, -2};
		cnt++;
	}
	
//	printf("#1 %d %d %d\n", result.first.first, result.first.second, result.second);
	if (result.second == -1) {
		if (card[4].size() != 0 && cnt < 20) {
			result = {{4, 0}, -2};
			cnt++;
		} else if (card[3].size() != 0) {
			result = {{3, 0}, -2};
		} else {
			long long pos = 0;
			for (int i = 1; i < m; i++) {
				long long up = proj[pos].second;
				long long down = proj[pos].first;
				long long new_up = proj[i].second;
				long long new_down = proj[i].first;
				if (down * new_up > up * new_down || (down * new_up == up * new_down && proj[i].first > proj[pos].first)) {
					pos = i;
				}
			}
			result = {{2, 0}, pos};
		}
	}
	
	int result_pos = card[result.first.first][result.first.second].second;
	card[result.first.first].erase(card[result.first.first].begin() + result.first.second);
	
//	printf("#2 %d %d %d\n", result.first.first, result.first.second, result.second);
	printf("%d %d\n", result_pos, result.second >= 0 ? result.second : 0);
	fflush(stdout);
	return result_pos;
}

void refill_card(int card_pos) {
	scanf("%d\n", &cur_money);
	int type, work, cost, pos = 0;
	long long cost_i = 1e18;
	int pos_i = -1;
	for (int i = 0; i < k; i++) {
		int t, w, c;
		scanf("%d %d %d", &t, &w, &c);
		if (i == 0) {
			type = t;
			work = w;
			cost = c;
			continue;
		}
		
		if (c > cur_money) {
			continue;
		}
		
		if (t == 4) {
			if (c >= 1ll * MAX_INVEST_COST * (1 << cnt)) {
				continue;
			}
			
			if (c < cost_i) {
				cost_i = c;
				pos_i = i;
			}
		}
		
		if (t != 0 && t != 1) {
			continue;
		}
		
		if (t == 0) {
			if (cost == 0) {
				if (1ll * w * 2 > 1ll * c * 3) {
					type = t;
					work = w;
					cost = c;
					pos = i;
				}
				continue;
			}
			
			if (1ll * w * cost > 1ll * work * c) {
				type = t;
				work = w;
				cost = c;
				pos = i;
			}
		} else {
			if (cost == 0) {
				if (1ll * w * m * 2 > 1ll * c * 3) {
					type = t;
					work = w * m;
					cost = c;
					pos = i;
				}
				continue;
			}
			
			if (1ll * w * cost > 1ll * work * c) {
				type = t;
				work = w * m;
				cost = c;
				pos = i;
			}
		}
	}
	
	if (t > 100 && pos_i != -1 && card[4].empty()) {
//		printf("# %d\n", t);
		type = 4;
		work = 0;
		pos = pos_i;
	}
	
	if (t == 0) {
		pos = 0;
	}
	
	card[type].push_back({work, card_pos});
	
	printf("%d\n", pos);
	fflush(stdout);
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &t);
	for (int i = 0; i < n; i++) {
		int t, w;
		scanf("%d %d", &t, &w);
		card[t].push_back({w, i});
	}
	for (int i = 0; i < m; i++) {
		int h, v;
		scanf("%d %d", &h, &v);
		proj[i] = {h, v};
	}
	
	while (t-- > 0) {
		int card_pos = use_card();
		
		for (int i = 0; i < m; i++) {
			int h, v;
			scanf("%d %d", &h, &v);
			proj[i] = {h, v};
		}
		
		refill_card(card_pos);
	}
	
	return 0;
}