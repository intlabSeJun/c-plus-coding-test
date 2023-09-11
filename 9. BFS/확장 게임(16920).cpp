// https://www.acmicpc.net/problem/16920

#include<iostream>
#include<queue>
#include<utility>
#include<string>
#include<vector>
using namespace std;

long long map[1001][1001];
int castle_num[10];
int iter_num[10];
int total_zero = 0;
int total_castle = 0;

queue<pair<int, int>> Q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0, 0,-1,1 };

void print_map(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void search(int x, int y, int N, int M, int n_castle) {
	int new_x, new_y;
	for (int i = 0; i < 4; i++) {
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
		else if (map[new_x][new_y] == -1 || (map[new_x][new_y] != map[x][y] && map[new_x][new_y] != 0)) continue;
		if (map[new_x][new_y] == 0) {
			map[new_x][new_y] = map[x][y];
			Q.push({ new_x, new_y });
			castle_num[map[x][y]]++;
			total_castle++;
		}
		if (total_castle == total_zero) break;
		if (n_castle > 1) search(new_x, new_y, N, M, n_castle - 1);
	}
}
void bfs(int N, int M) {
	pair<int, int> p;
	int n_castle;
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		n_castle = iter_num[map[p.first][p.second]];

		search(p.first, p.second, N, M, n_castle);
		if (total_castle == total_zero) break;
		//print_map(N, M);
	}
}

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	int N, M, P;
	cin >> N >> M >> P;
	
	for (int i = 1; i <= P; i++) cin >> iter_num[i];


	vector<vector<pair<int, int>>> V(P+1);
	string s;
	int x;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '#') map[i][j] = -1;
			else if (s[j] == '.') continue;
			else {
				x = s[j] - '0';
				V[x].push_back({ i,j });
				map[i][j] = x;
				total_zero++;
			}
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= P; i++) {
		for (int j = 0; j < V[i].size(); j++) {
			pair<int, int> p;
			p = V[i][j];
			cout << p.first << " " << p.second << "\n";
		}
	}*/

	for (int i = 1; i <= P; i++) {
		for (int j = 0; j < V[i].size(); j++) {
			Q.push(V[i][j]);
			castle_num[i]++;
			total_castle++;
		}
	}
	V.empty();
	bfs(N, M);

	for (int i = 1; i <= P; i++) cout << castle_num[i] << " ";
}