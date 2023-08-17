// https://www.acmicpc.net/problem/13913

#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;


int map_check[200005];

int dx[2] = { -1,1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	if (N == K) cout << 0 << "\n" << N;
	else if (N > K) {
		cout << N - K << "\n";
		for (int i = 0; i <= N - K; i++) {
			cout << N - i << " ";
		}
	}
	else if (N == 0 && K == 1) {
		cout << 1 << "\n" << 0 << " " << 1;
	}
	else {
		queue<pair<int, vector<int>>> Q;
		vector<int> v, buf_v;
		v.push_back(N);
		map_check[N] = 1;
		if (N == 0) {
			N = 1;
			v.push_back(N);
			map_check[1] = 2;
		}
		Q.push({ N, v });

		pair<int, vector<int>> p;
		int new_x, flag=0;
		while (!Q.empty()) {
			p = Q.front();
			Q.pop();
			for (int i = 0; i < 3; i++) {
				if (i == 2) new_x = p.first * 2;
				else new_x = p.first + dx[i];
				if (new_x == K) {
					cout << map_check[p.first] << "\n";
					for (int e : p.second) cout << e << " ";
					cout << K;
					flag = 1;
					break;
				}
				if (new_x < 0 || new_x > K * 2 || new_x > 200000) continue;
				if (map_check[new_x] != 0) continue;
			
				buf_v = p.second;
				map_check[new_x] = map_check[p.first] + 1;
				buf_v.push_back(new_x);
				Q.push({ new_x, buf_v});
				buf_v.clear();
			}
			if (flag == 1) break;
		}
	}
}