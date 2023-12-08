/*
Greedy = 지금 가장 최적인 답을 근시안적으로 택하는 알고리즘
       = 관찰을 통해 탐색 범위를 줄이는 알고리즘

이상적인 풀이 흐름
 1. 관찰을 통해 탐색 범위를 줄이는 방법 고안(시간 복잡도 감소하는 방향)
 2. 탐색 범위를 줄여도 올바른 결과를 낸다는 사실을 수학적으로 증명
 3. 구현해서 문제 통과.

 그리디는 잘못된 방법을 고안할 확률이 있으므로 가장 나중에 풀자

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
