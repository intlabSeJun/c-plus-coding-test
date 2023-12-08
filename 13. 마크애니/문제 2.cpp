#include<iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{   
    int max_dist = 0;
    for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board[0].size(); y++) {
            if (board[x][y] == 0) continue;

            // get max x dist
            int x_init_point = 0;
            for (int k = x; k < board.size(); k++) {
                if (board[k][y] == 0) {
                    x_init_point = k;
                    break;
                }
                else if (k == board.size() - 1) x_init_point = board.size() - 1;
            }
            
            int x_min_dist = x_init_point - x + 1;
            int x_cur_dist = x_min_dist;
            // search y and x, find min_dist for regular square
            for (int p_y = 1; p_y < x_min_dist; p_y++) {  // y direction
                for (int p_x = 0; p_x < x_min_dist; p_x++) {  // x direction
                    if (p_x + x >= board.size() || p_y + y >= board[0].size()) break;
                    if (board[p_x + x][p_y + y] == 0) {
                        x_cur_dist = p_x - x;
                        break;
                    }
                }
            }
            if (max_dist < x_cur_dist) max_dist = x_cur_dist * x_cur_dist;
        }
    }

    // // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;

    return max_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> map(4, vector<int>(4));

    int x;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j];
        } 
    }
    cout << solution(map);
}