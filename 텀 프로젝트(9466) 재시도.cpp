// https://www.acmicpc.net/problem/9466

/* 방법
   1. 자기자신을 가르키면 팀 생성됨
   2. 아닐시 자기자신을 가르킬 때까지 반복
   3. 자기자신이 안나오면 팀에 속하지 못하는 것임
   4. 방문여부를 1로 체크하고, 만약 체크된 곳을 가르킨다면 팀에 속하지 못하는 것임.
      + 이미 앞에서 팀에 속하는 사람들을 1로 체크하였기 때문에 가능함. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int n;
    
    for (int i = 0; i < T; i++) {
        cin >> n;
        vector<int> map(n+1);
        vector<int> map_check(n+1);
        for (int j = 1; j <= n; j++) cin >> map[j];

        int count = 0, count_buf=0;
        int target;
        for (int k = 1; k <= n; k++) {
            target = k;
            count_buf = 0;
            while (map_check[target] == 0) {
                map_check[target] = 1;
                if (map[target] == k) break;
                target = map[target];
                count_buf++;
            }
            while (map_check[target] != k && map_check[target] == 1 && count_buf != 0) {
                map_check[target] = k;
                target = map[target];
                count_buf--;
            }
            count += count_buf;
        }
        cout << count << "\n";
    }
}