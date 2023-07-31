// https://www.acmicpc.net/problem/9466

/* ���
   1. �ڱ��ڽ��� ����Ű�� �� ������
   2. �ƴҽ� �ڱ��ڽ��� ����ų ������ �ݺ�
   3. �ڱ��ڽ��� �ȳ����� ���� ������ ���ϴ� ����
   4. �湮���θ� 1�� üũ�ϰ�, ���� üũ�� ���� ����Ų�ٸ� ���� ������ ���ϴ� ����.
      + �̹� �տ��� ���� ���ϴ� ������� 1�� üũ�Ͽ��� ������ ������. */

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