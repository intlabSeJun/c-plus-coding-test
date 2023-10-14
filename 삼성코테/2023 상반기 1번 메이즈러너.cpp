#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int N, M, K;
int map[15][15] = {};
queue<pair<int, int>> person_coord;
pair<int, int> exit_coord;
int total_distance = 0, dist_shortest = 9999;

void print_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(map[i][j] < 0)
                cout << map[i][j] << " ";
            else
                cout <<  map[i][j] << "  ";
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
            else if (map[i][j] == -2) {
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
    int length_a = abs(left_upper_x - right_bottom_x)+1; // ���簢�� ���� ����
    int length_b = abs(left_upper_y - right_bottom_y)+1; // ���簢�� ���� ����

    //cout << "left_upper_x,y " << left_upper_x << " " << left_upper_y << " right_bottom_x,y " << right_bottom_x << " " << right_bottom_y << "\n";
    if (length_a != length_b) { // ����, ���� ���̰� �ٸ���
        if (length_a == bbox_lenght) { // ���� ���� > ���� ����
            start_x = left_upper_x;
            end_x = right_bottom_x;
            for (int c = 1; c <= bbox_lenght - length_b; c++) { // �������� ���簢�� �ִ��� �����.
                if (left_upper_y - c < 0) break;
                start_y = left_upper_y - c;
            }
            if (start_y == -1) { // �������� ���簢�� �� ���� �� ����
                for (int d = 1; d <= bbox_lenght - length_b; d++) { // ���������� ���簢�� �ִ��� �����.
                    if (right_bottom_y + d >= N) break;
                    end_y = right_bottom_y + d;
                }
                start_y = left_upper_y;
            }
            else end_y = right_bottom_y;

        }
        else { // ���� ���� > ���� ����
            start_y = left_upper_y;
            end_y = right_bottom_y;
            for (int a = 1; a <= bbox_lenght - length_a; a++) { // �������� ���簢�� �ִ��� �����.
                if (left_upper_x - a < 0) break;
                start_x = left_upper_x - a;
            }
            if (start_x == -1) { // �������� ���簢�� �� ���� �� ����
                for (int b = 1; b <= bbox_lenght - length_a; b++) { // ���������� ���簢�� �ִ��� �����.
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


    int map_copy[15][15] = {};
    for (int i = 0; i < bbox_lenght; i++) { // map�� bbox ���� copy
        for (int j = 0; j < bbox_lenght; j++) {
            map_copy[i][j] = map[start_x + bbox_lenght-1 - j][start_y + i];
        }
    }

    for (int i = 0; i < bbox_lenght; i++) { // ȸ���� ��� map�� �ְ� -1
        for (int j = 0; j < bbox_lenght; j++) {
            if (map_copy[i][j] > 0)
                map[start_x + i][start_y + j] = map_copy[i][j] - 1;
            else
                map[start_x + i][start_y + j] = map_copy[i][j];
        }
    }
}

void map_rotate(int out_M) {
    int cur_M = M - out_M; // ���� ���� �ִ� ���
    if (cur_M == 0) {
        //cout << "cur_M == 0\n";
        return;
    }

    int x, y, dist, x_short = 15, y_short = 15;
    for (int s = 0; s < cur_M; s++) {
        x = person_coord.front().first;
        y = person_coord.front().second;
        person_coord.push({ x,y });
        person_coord.pop();

        //cout << "uf\n";
        dist = get_distance(x, y, exit_coord.first, exit_coord.second);
        if (dist == dist_shortest) {
            if (x < x_short) { // ��>�� ������ ª�� ������ ã��(�����ǥ)
                x_short = x;
                y_short = y;
            }
            else if (x == x_short) { // �� ���� ������ ���� ª�� ���
                if (y < y_short) {
                    x_short = x;
                    y_short = y;
                }
            }
        }
    }
    //cout << "short_x,y " << x_short << " " << y_short << "\n";
    //cout << "dist_shortest " << dist_shortest << "\n";
    _rotation(x_short, y_short, exit_coord.first, exit_coord.second);
    //cout << "111111rotation\n";
    //print_map();

    person_coord_reset();
}

void func() {
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int cur_x, cur_y, new_x, new_y, cur_dist, new_dist;
    int out_M = 0, cur_M, move=0;

    while (K--) {
        cur_M = M - out_M;
        if (cur_M == 0) break;
        dist_shortest = 9999; // ���� ª�� ���� ����
        //cout << "size of queue " << person_coord.size() << "\n";
        //print_map();

        for (int j = 0; j < cur_M; j++) { // ���� ����� ������ ���ؼ� ����
            cur_x = person_coord.front().first;
            cur_y = person_coord.front().second;
            cur_dist = get_distance(cur_x, cur_y, exit_coord.first, exit_coord.second);

            move = 0;
            for (int i = 0; i < 4; i++) { // �����¿� 4���� �̵� ����
                new_x = cur_x + dx[i];
                new_y = cur_y + dy[i];
                if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
                if (map[new_x][new_y] > 0) continue; // ���� ���
                //cout <<"cur x,y " << cur_x << " " << cur_y << " new x,y " << new_x << " " << new_y << "\n";
                new_dist = get_distance(new_x, new_y, exit_coord.first, exit_coord.second);
                if (new_dist >= cur_dist) continue;

                total_distance++; //�̵��Ÿ� ����
                move = 1;
                if (new_dist == 0) { // ��ǥ������ ��쿡 ����
                    out_M++; // ���� ��� �߰�
                    map[cur_x][cur_y] = 0;
                    cur_dist = 9999;
                    break;
                }
                if(new_dist < dist_shortest) dist_shortest = new_dist; // ª�� �Ÿ� ����

                //cout << "cur_x,y " << cur_x << " " << cur_y << " " << "dist_shortest " << dist_shortest << "\n";

                person_coord.push({ new_x, new_y }); // �ٲ� ��ǥ ����
                map[new_x][new_y] = -2; // map����
                map[cur_x][cur_y] = 0;
                break;
            }
            if (cur_dist < dist_shortest) dist_shortest = cur_dist; //person - exit ª�� �Ÿ� ����

            // ����� �̵� ����, ���ε� ������ �� ����
            if (move == 0)
                person_coord.push({ cur_x, cur_y }); // ���� ��ǥ ����
            person_coord.pop(); // �ֱ� ��ǥ ����
        }
        //print_map();
        map_rotate(out_M);
        //cout << "rotation\n";
        //print_map();
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

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        person_coord.push({ x - 1,y - 1 });
        map[x - 1][y - 1] = -2;
    }
    cin >> x >> y;
    exit_coord = { x - 1,y - 1 };
    map[x - 1][y - 1] = -1;

    //print_map();

    func();
    cout << total_distance << "\n";
    cout << exit_coord.first+1 << " " << exit_coord.second+1;

    return 0;
}