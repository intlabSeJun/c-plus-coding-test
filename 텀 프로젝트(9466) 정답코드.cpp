// https://www.acmicpc.net/problem/9466

/* 방법
   1. 자기자신을 가르키면 팀 생성됨
   2. 아닐시 자기자신을 가르킬 때까지 반복
   3. 자기자신이 안나오면 팀에 속하지 못하는 것임
   4. 방문여부를 1로 체크하고, 만약 체크된 곳을 가르킨다면 팀에 속하지 못하는 것임.
      + 이미 앞에서 팀에 속하는 사람들을 1로 체크하였기 때문에 가능함. */

#include<iostream>
using namespace std;

int map[100005];
int map_check[100005];

const int Not_visited = 0;
const int Cycle_in = -1;

void run(int i) {
    int cur = i;
    while (1) {
        map_check[cur] = i;
        cur = map[cur];

        if (map_check[cur] == i) {
            while (map_check[cur] != Cycle_in) {
                map_check[cur] = Cycle_in;
                cur = map[cur];
            }
            return;
        }
        else if (map_check[cur] != 0) return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    int n;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> map[i];

        for (int i = 1; i <= n; i++) map_check[i] = Not_visited;

        for (int i = 1; i <= n; i++) {
            if (map_check[i] == Not_visited) run(i);
        }

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (map_check[i] != Cycle_in) count++;
        }
        cout << count << "\n";
    }
}