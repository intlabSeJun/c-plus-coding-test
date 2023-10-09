// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/82284615e5814db489ee482ef77bcaf4
#include<iostream>
using namespace std;

int board1[21][21];
int board2[21][21];
int n;

void rotate() { // board2�� �ð� �������� 90�� ȸ���ϴ� �Լ�
    int tmp[21][21];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j] = tmp[n - 1 - j][i];
}

void tilt(int dir) {
    while (dir--) rotate();
    for (int i = 0; i < n; i++) {
        int tilted[21] = {}; // board2[i]�� �������� ����� ����� ������ ����
        int idx = 0; // tilted �迭���� ��� �����ؾ� �ϴ��� ����Ű�� ����
        for (int j = 0; j < n; j++) {
            if (board2[i][j] == 0) continue;
            if (tilted[idx] == 0) // ������ ��ġ�� ������� ���
                tilted[idx] = board2[i][j];
            else if (tilted[idx] == board2[i][j]) // ���� ���� ���� ����� �浹�� ���
                tilted[idx++] *= 2;
            else // �ٸ� ���� ���� ����� �浹
                tilted[++idx] = board2[i][j];
        }
        for (int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]�� tilted�� ���
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];

    int mx = 0;
    for (int tmp = 0; tmp < 1024; tmp++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;
}