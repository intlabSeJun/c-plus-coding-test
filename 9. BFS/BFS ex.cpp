#include<iostream>
#include<queue>
#include<utility>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

// 1과 0으로 이루어진 grid, 목표는 BFS를 이용하여 1을 찾아내는 것이다.
int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수

// (x,y)로의 상하좌우 네 방향을 의미
// x는 행방향, y는 열방향. 시작 좌표는 좌측상단(0,0)
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> > Q;
    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    Q.push({ 0,0 }); // 큐에 시작점인 (0, 0)을 삽입.
    while (!Q.empty()) { // 찾을 파란점(1)이 없을 때까지 계속.
        pair<int, int> cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++) { // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            Q.push({ nx,ny });
        }
    }
}