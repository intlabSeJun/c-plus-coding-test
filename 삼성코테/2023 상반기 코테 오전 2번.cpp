#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 2000

int n, m, p;

// 각 토끼의 id를 기록해줍니다.
int id[MAX_N + 1];

// 각 토끼의 이동거리를 기록해줍니다.
int pw[MAX_N + 1];

// 각 토끼의 점프 횟수를 기록해줍니다.
int jump_cnt[MAX_N + 1];

// 각 토끼의 점수를 기록해줍니다.
long long result[MAX_N + 1];

// 각 토끼의 현재 위치(좌표)를 기록해줍니다.
pair<int, int> point[MAX_N + 1];

// 각 토끼의 id를 인덱스 번호로 변환해줍니다.
map<int, int> id_to_idx;

// 각각의 경주에서 토끼가 달렸는지 여부를 기록해줍니다.
bool is_runned[MAX_N + 1];

// 하나를 제외한 모든 토끼의 점수를 더하는 쿼리를 편하게 하기 위해
// total_sum이라는 변수를 추가해줍니다.
long long total_sum;

// 구조체 Rabbit을 정리해 관리합니다.
struct Rabbit {
    int x, y, j, id;

    // 이동할 토끼를 결정하기 위해 정렬함수를 만들어줍니다.
    bool operator <(const Rabbit& b) const {
        if (j != b.j) return j > b.j;
        if (x + y != b.x + b.y) return x + y > b.x + b.y;
        if (x != b.x) return x > b.x;
        if (y != b.y) return y > b.y;
        return id > b.id;
    }
};

// 가장 긴 위치를 판단하기 위해 정렬함수를 하나 더 만들어줍니다.
bool Cmp(Rabbit a, Rabbit b) {
    if (a.x + a.y != b.x + b.y) return a.x + a.y < b.x + b.y;
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}

// 경주 시작 준비 쿼리를 처리해줍니다.
void init() {
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> id[i] >> pw[i];
        id_to_idx[id[i]] = i;
        point[i] = make_pair(1, 1);
    }
}

// 토끼를 위로 이동시킵니다.
Rabbit GetUpRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit up_rabbit = cur_rabbit;
    dis %= 2 * (n - 1);

    if (dis >= up_rabbit.x - 1) {
        dis -= (up_rabbit.x - 1);
        up_rabbit.x = 1;
    }
    else {
        up_rabbit.x -= dis;
        dis = 0;
    }

    if (dis >= n - up_rabbit.x) {
        dis -= (n - up_rabbit.x);
        up_rabbit.x = n;
    }
    else {
        up_rabbit.x += dis;
        dis = 0;
    }

    up_rabbit.x -= dis;

    return up_rabbit;
}

// 토끼를 아래로 이동시킵니다.
Rabbit GetDownRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit down_rabbit = cur_rabbit;
    dis %= 2 * (n - 1);

    if (dis >= n - down_rabbit.x) {
        dis -= (n - down_rabbit.x);
        down_rabbit.x = n;
    }
    else {
        down_rabbit.x += dis;
        dis = 0;
    }

    if (dis >= down_rabbit.x - 1) {
        dis -= (down_rabbit.x - 1);
        down_rabbit.x = 1;
    }
    else {
        down_rabbit.x -= dis;
        dis = 0;
    }

    down_rabbit.x += dis;

    return down_rabbit;
}

// 토끼를 왼쪽으로 이동시킵니다.
Rabbit GetLeftRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit left_rabbit = cur_rabbit;
    dis %= 2 * (m - 1);

    if (dis >= left_rabbit.y - 1) {
        dis -= (left_rabbit.y - 1);
        left_rabbit.y = 1;
    }
    else {
        left_rabbit.y -= dis;
        dis = 0;
    }

    if (dis >= m - left_rabbit.y) {
        dis -= (m - left_rabbit.y);
        left_rabbit.y = m;
    }
    else {
        left_rabbit.y += dis;
        dis = 0;
    }

    left_rabbit.y -= dis;

    return left_rabbit;
}

// 토끼를 오른쪽으로 이동시킵니다.
Rabbit GetRightRabbit(Rabbit cur_rabbit, int dis) {
    Rabbit right_rabbit = cur_rabbit;
    dis %= 2 * (m - 1);

    if (dis >= m - right_rabbit.y) {
        dis -= (m - right_rabbit.y);
        right_rabbit.y = m;
    }
    else {
        right_rabbit.y += dis;
        dis = 0;
    }

    if (dis >= right_rabbit.y - 1) {
        dis -= (right_rabbit.y - 1);
        right_rabbit.y = 1;
    }
    else {
        right_rabbit.y -= dis;
        dis = 0;
    }

    right_rabbit.y += dis;

    return right_rabbit;
}


// 경주를 진행합니다.
void start_round() {
    int k, bonus;
    cin >> k >> bonus;
    priority_queue <Rabbit> rabbit_pq;

    for (int i = 1; i <= p; i++) {
        is_runned[i] = false;
    }

    // 우선 p마리의 토끼들을 전부 priority queue에 넣어줍니다.
    for (int i = 1; i <= p; i++) {
        Rabbit new_rabbit;
        new_rabbit.x = point[i].first;
        new_rabbit.y = point[i].second;
        new_rabbit.j = jump_cnt[i];
        new_rabbit.id = id[i];

        rabbit_pq.push(new_rabbit);
    }

    // 경주를 k회 진행합니다.
    while (k--) {
        // 우선순위가 가장 높은 토끼를 priority queue에서 뽑아옵니다.
        Rabbit cur_rabbit = rabbit_pq.top(); rabbit_pq.pop();

        // 해당 토끼를 상, 하, 좌, 우 4개의 방향으로 이동시킵니다.
        // 각각의 방향으로 이동시킨 후 최종 위치를 구하고
        // 가장 시작점으로부터 멀리 있는 위치를 찾아줍니다.
        int dis = pw[id_to_idx[cur_rabbit.id]];
        Rabbit nex_rabbit = cur_rabbit;
        nex_rabbit.x = 0;
        nex_rabbit.y = 0;


        // 토끼를 위로 이동시킵니다.
        Rabbit up_rabbit = GetUpRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, up_rabbit)) nex_rabbit = up_rabbit;


        // 토끼를 아래로 이동시킵니다.
        Rabbit down_rabbit = GetDownRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, down_rabbit)) nex_rabbit = down_rabbit;


        // 토끼를 왼쪽으로 이동시킵니다.
        Rabbit left_rabbit = GetLeftRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, left_rabbit)) nex_rabbit = left_rabbit;


        // 토끼를 오른쪽으로 이동시킵니다.
        Rabbit right_rabbit = GetRightRabbit(cur_rabbit, dis);
        // 지금까지의 도착지들보다 더 멀리 갈 수 있다면 도착지를 갱신합니다.
        if (Cmp(nex_rabbit, right_rabbit)) nex_rabbit = right_rabbit;


        // 토끼의 점프 횟수를 갱신해주고, priority queue에 다시 집어넣습니다.
        nex_rabbit.j++;
        rabbit_pq.push(nex_rabbit);

        // 실제 point, jump_cnt 배열에도 값을 갱신해줍니다.
        int nex_idx = id_to_idx[nex_rabbit.id];
        point[nex_idx] = make_pair(nex_rabbit.x, nex_rabbit.y);
        jump_cnt[nex_idx]++;

        // 토끼가 달렸는지 여부를 체크해줍니다.
        is_runned[nex_idx] = true;

        // 토끼가 받는 점수는 (현재 뛴 토끼)만 (r + c)만큼 점수를 빼주고,
        // 모든 토끼(total_sum)에게 (r + c)만큼 점수를 더해줍니다.
        // 최종적으로 i번 토끼가 받는 점수는 result[i] + total_sum이 됩니다.
        result[nex_idx] -= (nex_rabbit.x + nex_rabbit.y);
        total_sum += (nex_rabbit.x + nex_rabbit.y);
    }

    // 보너스 점수를 받을 토끼를 찾습니다.
    // 이번 경주때 달린 토끼 중 가장 멀리있는 토끼를 찾습니다.
    Rabbit bonus_rabbit;
    bonus_rabbit.x = 0;
    bonus_rabbit.y = 0;
    while (!rabbit_pq.empty()) {
        Rabbit cur_rabbit = rabbit_pq.top(); rabbit_pq.pop();

        // 달리지 않은 토끼는 스킵합니다.
        if (!is_runned[id_to_idx[cur_rabbit.id]]) continue;

        if (Cmp(bonus_rabbit, cur_rabbit))
            bonus_rabbit = cur_rabbit;
    }

    // 해당 토끼에게 bonus만큼 점수를 추가해줍니다.
    result[id_to_idx[bonus_rabbit.id]] += bonus;
}

// 이동거리를 변경합니다.
void power_up() {
    int id, t;
    cin >> id >> t;
    int idx = id_to_idx[id];

    pw[idx] *= t;
}

// 최고의 토끼를 선정합니다.
void print_result() {
    long long ans = 0;
    for (int i = 1; i <= p; i++)
        ans = max(ans, result[i] + total_sum);

    cout << ans;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int query;
        cin >> query;
        // 경주 시작 준비 쿼리를 처리해줍니다.
        if (query == 100) {
            init();
        }
        // 경주를 진행합니다.
        if (query == 200) {
            start_round();
        }
        // 이동거리를 변경합니다.
        if (query == 300) {
            power_up();
        }
        // 최고의 토끼를 선정합니다.
        if (query == 400) {
            print_result();
        }
    }
}