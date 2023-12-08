/*
Greedy = ���� ���� ������ ���� �ٽþ������� ���ϴ� �˰���
       = ������ ���� Ž�� ������ ���̴� �˰���

�̻����� Ǯ�� �帧
 1. ������ ���� Ž�� ������ ���̴� ��� ���(�ð� ���⵵ �����ϴ� ����)
 2. Ž�� ������ �ٿ��� �ùٸ� ����� ���ٴ� ����� ���������� ����
 3. �����ؼ� ���� ���.

 �׸���� �߸��� ����� ����� Ȯ���� �����Ƿ� ���� ���߿� Ǯ��

*/
#include<iostream>
#include<queue>
using namespace std;

int N, K;
priority_queue<int> PQ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int x;
    
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x > K) continue;
        else if (x == K) {
            cout << 1;
            return 0;
        }
        PQ.push(x);
    }

    int total_cnt = 0;
    int cur_k = K;
 

    while (!PQ.empty()) {
       
        if (cur_k == 0) break;
        int cur_v = PQ.top();
        PQ.pop();
        total_cnt += (cur_k / cur_v);
        cur_k = cur_k % cur_v;
    }
    
    cout << total_cnt;
}
