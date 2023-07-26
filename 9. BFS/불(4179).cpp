//https://www.acmicpc.net/problem/4179

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<string>
using namespace std;

void print_map(vector<string> &map) {
	/* map의 현재 상태 출력.
	코드가 의도한대로 동작하는지 확인.*/
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

	vector<string> map(R); // 문자열 맵 생성
	vector<vector<int>> map_check(R, vector<int>(C)); //이동여부 및 이동거리 체크
	queue<pair<int, int>> Q; // 사용할 큐
	queue<pair<int, int>> Q_for_Fire;  // 임시 큐, F만 담아서 위의 Q에 옮겨줄 예정

	for (int i = 0; i < R; i++) { //문자열 받아서 map과 Q, Q_for_Fire에 할당.
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'J') {
				Q.push({ i, j });
				map_check[i][j] = 1;
			}
			else if (map[i][j] == 'F') Q_for_Fire.push({ i,j });
		}
	}

	while (!Q_for_Fire.empty()) {
		// F들의 좌표를 Q에 쌓는다.
		// Q에서 front()를 J 좌표로 설정하기 위함.
		Q.push(Q_for_Fire.front());
		Q_for_Fire.pop();
	}

	int dx[4] = { -1, 1, 0,0 };
	int dy[4] = { 0,0,-1,1 };

	pair<int, int> p;
	int x, y; // 갱신할 상하좌우 좌표
	int short_cut=0; //가장 짧은 거리 나타냄
	int flag_F = 0; // 1이면, F가 J를 모두 잡은 것.
	int flag_J = 0;  // 1이면, J가 탈출. -1이면 J가 이동.
	int J_count = 1; // F가 J를 잡아을 때, 1이면 모든 J를 잡은 것.
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		flag_J = 0; // J의 이동여부 및 탈출 변수 초기화
		for (int i = 0; i < 4; i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if ((x == R || y == C || x == -1 || y==-1) && map[p.first][p.second] == 'J') {
				// J가 탈출할 시 수행.
				short_cut = map_check[p.first][p.second]+1;
				flag_J = 1;
				break;
			}
			else if (x < 0 || x >= R || y < 0 || y >= C) continue;
			else if (map[x][y] == '#'|| map[x][y] == 'F') continue;
			else if (map[p.first][p.second] == 'J' && map_check[x][y] == 0) {
				// J가 이동시 수행.
				Q.push({ x,y });
				map[x][y] = 'J'; // 맵에 새로운 J 할당
				map_check[x][y] = map_check[p.first][p.second] + 1; // 이동거리 증가시켜줌
				flag_J = -1; // J 이동했다고 표시.
				J_count++; // 새로 생겨난 J수만큼 count.
			}
			else if (map[p.first][p.second] == 'F') {
				// F가 이동시 수행
				if (map[x][y] == 'J' && J_count == 1) {
					// J를 잡고, J의 개수가 1개 남았을 때, 모든 J를 잡은 것.
					flag_F = 1; // J 다 잡았다고 표시.
					break;
				}
				map[x][y] = 'F'; // 맵에 새로운 F 할당
				Q.push({x,y});
			}
			//cout << J_count << "\n";
		}
		
		/*cout << "\n";
		print_map(map);*/
	
		if (flag_J == -1) {
			// J가 이동했을 시
			J_count--; // 총 J의 수를 감소
			map[p.first][p.second] = '.'; // 이전 J의 맵 변경
		}
		if (flag_J == 1) {
			// J가 탈출했을 시
			cout << short_cut-1; // 최단거리 출력
			break;
		}
		else if (flag_F==1) {
			// J를 모두 잡았을 시
			cout << "IMPOSSIBLE";
			break;
		}
	}
	// J가 벽에 막힌 경우에 수행.
	if (flag_J!=1 && flag_F!=1) cout << "IMPOSSIBLE";
}