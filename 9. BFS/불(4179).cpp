//https://www.acmicpc.net/problem/4179

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
using namespace std;

void print_map(vector<string> &map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++)
			cout << map[i][j];
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;

	vector<string> map(R);
	vector<vector<int>> map_check(R, vector<int>(C));
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q_for_Fire; 

	int j_x, j_y;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'J') {
				j_x = i;
				j_y = j;
				map_check[i][j] = 1;
			}
			else if (map[i][j] == 'F') Q_for_Fire.push({ i,j });
		}
	}
	Q.push({ j_x, j_y });
	while (!Q_for_Fire.empty()) {
		Q.push(Q_for_Fire.front());
		Q_for_Fire.pop();
	}

	int dx[4] = { -1, 1, 0,0 };
	int dy[4] = { 0,0,-1,1 };

	pair<int, int> p;
	int x, y;
	int short_cut=0;
	int flag_F = 0, flag_J=0;
	int J_count = 1;
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		flag_J = 0;
		for (int i = 0; i < 4; i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if ((x == R || y == C || x == -1 || y==-1) && map[p.first][p.second] == 'J') {
				short_cut = map_check[p.first][p.second]+1;
				flag_J = 1;
				break;
			}
			else if (x < 0 || x >= R || y < 0 || y >= C) continue;
			else if (map[x][y] == '#'|| map[x][y] == 'F') continue;
			else if (map[p.first][p.second] == 'J' && map_check[x][y] == 0) {
				Q.push({ x,y });
				map[x][y] = 'J';
				map_check[x][y] = map_check[p.first][p.second] + 1;
				flag_J = -1;
				J_count++;
			}
			else if (map[p.first][p.second] == 'F') {
				if (map[x][y] == 'J' && J_count == 1) {
					flag_F = 1;
					break;
				}
				map[x][y] = 'F';
				Q.push({x,y});
			}
			//cout << J_count << "\n";
		}
		
		/*cout << "\n";
		print_map(map);*/
	
		if (flag_J == -1) {
			J_count--;
			map[p.first][p.second] = '.';
		}
		if (flag_J == 1) {
			cout << short_cut-1;
			break;
		}
		else if (flag_F==1) {
			cout << "IMPOSSIBLE";
			break;
		}
	}
	if (flag_J!=1 && flag_F!=1) cout << "IMPOSSIBLE";
}