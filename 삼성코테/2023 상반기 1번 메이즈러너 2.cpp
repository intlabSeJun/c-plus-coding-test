#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int N, M, K;
int map[15][15] = {};
queue<pair<int, int>> person_coord;
pair<int, int> exit_coord;
int total_distance = 0, dist_shortest = 9999, max_a_b = 9999;

void print_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] < 0)
                cout << map[i][j] << " ";
            else
                cout << map[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int get_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}


void person_coord_reset() {
    //person_coord.empty();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == -1)
                exit_coord = { i,j };
            else if (map[i][j] <= -2) {
                //cout << "1" << person_coord.size() << "\n";
                person_coord.pop();
                person_coord.push({ i,j });
                //cout << i << " " << j << "\n";
            }
        }
    }
}

int get_max_min(int x, int y, int flag) {
    if (flag == 1) {  // max
        if (x >= y) return x;
        else return y;
    }
    else if (flag == 2) { // min
        if (x < y) return x;
        else return y;
    }
    else
        return 0;
}

void _rotation(int x, int y, int x_t, int y_t) {
    int start_x = -1, start_y = -1, end_x = -1, end_y = -1;

    int bbox_lenght = get_max_min(abs(x - x_t), abs(y - y_t), 1) + 1;
    int left_upper_x = get_max_min(x, x_t, 2); // min
    int left_upper_y = get_max_min(y, y_t, 2); // min
    int right_bottom_x = get_max_min(x, x_t, 1);
    int right_bottom_y = get_max_min(y, y_t, 1);
    int length_a = abs(left_upper_x - right_bottom_x) + 1; // 직사각형 세로 길이
    int length_b = abs(left_upper_y - right_bottom_y) + 1; // 직사각형 가로 길이

    //cout << "left_upper_x,y " << left_upper_x << " " << left_upper_y << " right_bottom_x,y " << right_bottom_x << " " << right_bottom_y << "\n";
    if (length_a != length_b) { // 가로, 세로 길이가 다르면
        if (length_a == bbox_lenght) { // 세로 길이 > 가로 길이
            start_x = left_upper_x;
            end_x = right_bottom_x;
            for (int c = 1; c <= bbox_lenght - length_b; c++) { // 왼쪽으로 정사각형 최대한 만들기.
                if (left_upper_y - c < 0) break;
                start_y = left_upper_y - c;
            }
            if (start_y == -1) { // 왼쪽으로 정사각형 못 만들 시 수행
                for (int d = 1; d <= bbox_lenght - length_b; d++) { // 오른쪽으로 정사각형 최대한 만들기.
                    if (right_bottom_y + d >= N) break;
                    end_y = right_bottom_y + d;
                }
                start_y = left_upper_y;
            }
            else end_y = right_bottom_y;

        }
        else { // 가로 길이 > 세로 길이
            start_y = left_upper_y;
            end_y = right_bottom_y;
            for (int a = 1; a <= bbox_lenght - length_a; a++) { // 위쪽으로 정사각형 최대한 만들기.
                if (left_upper_x - a < 0) break;
                start_x = left_upper_x - a;
            }
            if (start_x == -1) { // 위쪽으로 정사각형 못 만들 시 수행
                for (int b = 1; b <= bbox_lenght - length_a; b++) { // 오른쪽으로 정사각형 최대한 만들기.
                    if (right_bottom_x + b >= N) break;
                    end_x = right_bottom_x + b;
                }
                start_x = left_upper_x;
            }
            else end_x = right_bottom_x;
        }
    }
    else {
        start_x = left_upper_x;
        start_y = left_upper_y;
        end_x = right_bottom_x;
        end_y = right_bottom_y;
    }

    //cout << "start_x,y " << start_x << " " << start_y << " end_x,y " << end_x << " " << end_y << "\n";

    if (start_x == -1 || start_y == -1 || end_x == -1 || end_y == -1) {
        cout << "------- Error -------\n";
        cout << "start_x,y " << start_x << " " << start_y << " end_x,y " << end_x << " " << end_y << "\n";
        return;
    }

    //print_map();
    int map_copy[15][15] = {};
    for (int i = 0; i < bbox_lenght; i++) { // map에 bbox 값들 copy
        for (int j = 0; j < bbox_lenght; j++) {
            map_copy[i][j] = map[start_x + bbox_lenght - 1 - j][start_y + i];
        }
    }

    /*for (int i = 0; i < bbox_lenght; i++) {
        for (int j = 0; j < bbox_lenght; j++)
            cout << map_copy[i][j] << " ";
        cout << "\n";
    }*/

    for (int i = 0; i < bbox_lenght; i++) { // 회전한 행렬 map에 넣고 -1
        for (int j = 0; j < bbox_lenght; j++) {
            if (map_copy[i][j] > 0)
                map[start_x + i][start_y + j] = map_copy[i][j] - 1;
            else
                map[start_x + i][start_y + j] = map_copy[i][j];
        }
    }
    //print_map();
}

void map_rotate(int out_M) {
    int cur_M = M - out_M; // 현재 남아 있는 사람
    if (cur_M == 0) {
        //cout << "cur_M == 0\n";
        return;
    }

    int x, y, dist, x_short = 9999, y_short = 9999, max_a_b_buf;
    for (int s = 0; s < cur_M; s++) {
        //cout << "2" << person_coord.size() << "\n";
        x = person_coord.front().first;
        y = person_coord.front().second;
        person_coord.push({ x,y });
        person_coord.pop();

        //cout << "uf\n";
        dist = get_distance(x, y, exit_coord.first, exit_coord.second);
        cout << "x y " << x << y << " dist " << dist << "\n";
        max_a_b_buf = get_max_min(abs(x - exit_coord.first), abs(y - exit_coord.second), 1);
        if (dist == dist_shortest && max_a_b == max_a_b_buf) {
            cout << "max_a_b " << max_a_b_buf << " " << max_a_b << "\n";
            if (y < y_short) { // 행>열 순으로 짧은 지점을 찾음(사람좌표)
                x_short = x;
                y_short = y;
            }
            else if (y == y_short) { // 행 길이 같으면 열이 짧은 사람
                if (x < x_short) {
                    x_short = x;
                    y_short = y;
                }
            }
        }
    }
    //cout << "4" << person_coord.size() << "\n";
    cout << "short_x,y " << x_short << " " << y_short << "\n";
    cout << "dist_shortest " << dist_shortest << "\n";
    _rotation(x_short, y_short, exit_coord.first, exit_coord.second);
    //cout << "111111rotation\n";
    //print_map();

    person_coord_reset();
}

void func() {
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int cur_x, cur_y, new_x, new_y, cur_dist, new_dist, buf1;
    int out_M = 0, cur_M, move = 0, dubplicat_count = 0, dist_longest = 0;

    while (K--) {
        cur_M = M - out_M;
        if (cur_M == 0) break;
        dist_shortest = 9999; // 가장 짧은 길이 저장
        max_a_b = 9999;
        buf1 = 9999;
        //cout << "size of queue " << person_coord.size() << "\n";
        //print_map();

        for (int j = 0; j < cur_M; j++) { // 현재 사람들 각각에 대해서 수행
            cur_x = person_coord.front().first;
            cur_y = person_coord.front().second;
            cur_dist = get_distance(cur_x, cur_y, exit_coord.first, exit_coord.second);

            dubplicat_count = 0;
            move = 0;

            for (int i = 0; i < 4; i++) { // 상하좌우 4방향 이동 수행
                new_x = cur_x + dx[i];
                new_y = cur_y + dy[i];
                if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
                if (map[new_x][new_y] > 0) continue; // 벽일 경우
                //cout <<"cur x,y " << cur_x << " " << cur_y << " new x,y " << new_x << " " << new_y << "\n";
                new_dist = get_distance(new_x, new_y, exit_coord.first, exit_coord.second);
                if (new_dist >= cur_dist) continue;

                if (map[cur_x][cur_y] < -2)
                    dubplicat_count = (map[cur_x][cur_y] + 2) * -1;
                if (dubplicat_count != 0) {
                    for (int k = 0; k <= dubplicat_count; k++)
                        total_distance++; //이동거리 저장
                }
                else
                    total_distance++; //이동거리 저장

                move = 1;

                if (new_dist == 0) { // 목표지점일 경우에 종료
                    out_M++;
                    map[cur_x][cur_y] = 0;
                    cur_dist = 10000;
                    break;
                }
                if (new_dist <= dist_shortest) {
                    dist_shortest = new_dist; // 짧은 거리 저장
                    buf1 = get_max_min(abs(new_x - exit_coord.first), abs(new_y - exit_coord.second), 1);
                    max_a_b = buf1;
                    /*if (max_a_b > buf1)
                        max_a_b = buf1;*/
                }

                //cout << "cur_x,y " << cur_x << " " << cur_y << " " << "dist_shortest " << dist_shortest << "\n";

                if (map[new_x][new_y] <= -2) {
                    if (dubplicat_count != 0)
                        map[new_x][new_y] = map[new_x][new_y] - dubplicat_count - 1; // map변경
                    else
                        map[new_x][new_y] -= 1;
                    out_M++;
                }
                else {
                    person_coord.push({ new_x, new_y }); // 바뀐 좌표 저장
                    if (dubplicat_count != 0)
                        map[new_x][new_y] = -2 - dubplicat_count; // map변경
                    else
                        map[new_x][new_y] = -2;
                }
                map[cur_x][cur_y] = 0;
                break;
            }
            if (cur_dist <= dist_shortest) {
                dist_shortest = cur_dist; //person - exit 짧은 거리 저장
                buf1 = get_max_min(abs(cur_x - exit_coord.first), abs(cur_y - exit_coord.second), 1);
                max_a_b = buf1;
                /*if (max_a_b > buf1)
                    max_a_b = buf1;*/
            }

            // 사람이 이동 없고, 골인도 안했을 때 수행
            if (move == 0)
                person_coord.push({ cur_x, cur_y }); // 이전 좌표 저장
            //cout << "3" << person_coord.size() << "\n";
            person_coord.pop(); // 최근 좌표 제거
        }
        print_map();
        map_rotate(out_M);
        cout << "rotation\n";
        print_map();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int x, y, duple_count=0;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        if (map[x - 1][y - 1] == -2) {
            map[x - 1][y - 1] -= 1;
            duple_count++;
        }
        else {
            person_coord.push({ x - 1,y - 1 });
            map[x - 1][y - 1] = -2;
        }
    }
    M = M - duple_count;

    cin >> x >> y;
    exit_coord = { x - 1,y - 1 };
    map[x - 1][y - 1] = -1;

    //print_map();

    func();
    cout << total_distance << "\n";
    cout << exit_coord.first + 1 << " " << exit_coord.second + 1;

    return 0;
}