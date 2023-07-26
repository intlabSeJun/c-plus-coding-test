//https://www.acmicpc.net/problem/1697

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void print_map(vector<int>& map) {
	for (int i = 0; i < map.size(); i++) cout << map[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> map(200001, 0);
	map[N] = 1;

	queue<int> Q;
	Q.push(N);

	int x, new_x;
	int dx[3] = { 1, -1, 2 };
	int short_cut = 0, flag=0;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 2) new_x = x * dx[i];
			else new_x = x + dx[i];
	
			if (new_x == K) {
				flag = 1;
				short_cut = map[x]+1;
				break;
			}
			else if (new_x < 0 || new_x > 200000) continue;
			else if (map[new_x] >= 1) continue;
			Q.push(new_x);
			map[new_x] = map[x] + 1;
		}
		if (flag == 1) break;
	}
	if (N == K) cout << 0;
	else cout << short_cut-1;
}