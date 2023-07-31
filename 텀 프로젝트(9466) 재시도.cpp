// https://www.acmicpc.net/problem/9466

/* ���
   1. �ڱ��ڽ��� ����Ű�� �� ������
   2. �ƴҽ� �ڱ��ڽ��� ����ų ������ �ݺ�
   3. �ڱ��ڽ��� �ȳ����� ���� ������ ���ϴ� ����
   4. �湮���θ� 1�� üũ�ϰ�, ���� üũ�� ���� ����Ų�ٸ� ���� ������ ���ϴ� ����.
      + �̹� �տ��� ���� ���ϴ� ������� 1�� üũ�Ͽ��� ������ ������. */

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