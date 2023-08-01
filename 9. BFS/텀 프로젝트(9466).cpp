//https://www.acmicpc.net/problem/9466

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void print_map_check(vector<int>& map_check) {
	for (int i = 1; i < map_check.size(); i++) cout << map_check[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	int N;

	for (int i = 0; i < T; i++) {
		cin >> N;

		vector<int> map(N + 1);
		vector<int> map_check(N + 1);

		for (int j = 1; j <= N; j++) cin >> map[j];

		int x, flag, k2;
		int count = 0;
		for (int k = 1; k <= N; k++) {
			if (map[k] == k || map_check[k] == 1) {
				map_check[k] = 1;
				continue;
			}

			queue<int> Q, Q_buf;
			Q.push(map[k]);
			Q_buf.push(k);

			flag = 0;
			k2 = -k * 2;
			while (!Q.empty()) {
				x = Q.front();
				Q.pop();
				if (x == k) {
					flag = 1;
					break;
				}
				if (map[x] == x || map_check[x] == k2 || map_check[x] == -1) {
					break;
				}
				Q_buf.push(x);
				Q.push(map[x]);
				map_check[x] = k2;
				//print_map_check(map_check);
			}
			if (flag == 1) {
				while (!Q_buf.empty()) {
					x = Q_buf.front();
					Q_buf.pop();
					map_check[x] = 1;
					//print_map_check(map_check);
				}
			}
			else {
				while (!Q_buf.empty()) {
					count++;
					x = Q_buf.front();
					Q_buf.pop();
					map_check[x] = -1;
					//print_map_check(map_check);
				}
			}
		}
		//cout << count;
		cout << count << "\n";
	}
}