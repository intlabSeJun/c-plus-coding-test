#include<iostream>
#include<utility>
using namespace std;

int N, M;
int chick_check[15] = {};
pair<int, int> chick_coord[15];
pair<int, int> home_coord[110];
int home_count = 0, chick_count = 0;
int total_distance = 999999;

int get_distance(pair<int,int> &p1, pair<int,int> &p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void func(int k) {
	if (k == M) {
		int dist, cur_dist_total = 0;
		for (int i = 0; i < home_count; i++) {
			int shortest = 999999;
			for (int j = 0; j < M; j++) {
				dist = get_distance(home_coord[i], chick_coord[chick_check[j]]);
				if (dist < shortest) shortest = dist;
			}
			cur_dist_total += shortest;
		}
		if (total_distance > cur_dist_total) total_distance = cur_dist_total;
		return;
	}

	int st = 0;
	if (k != 0) st = chick_check[k-1] + 1;

	for (int i = st; i < chick_count; i++) {
		chick_check[k] = i;
		func(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x == 1) home_coord[home_count++] = { i, j };
			else if (x == 2) chick_coord[chick_count++] = { i,j };
		}
	}

	func(0);
	cout << total_distance;
}