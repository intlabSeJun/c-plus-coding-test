#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define MAX_N 2000

int n, m, p;

// �� �䳢�� id�� ������ݴϴ�.
int id[MAX_N + 1];

// �� �䳢�� �̵��Ÿ��� ������ݴϴ�.
int pw[MAX_N + 1];

// �� �䳢�� ���� Ƚ���� ������ݴϴ�.
int jump_cnt[MAX_N + 1];

// �� �䳢�� ������ ������ݴϴ�.
long long result[MAX_N + 1];

// �� �䳢�� ���� ��ġ(��ǥ)�� ������ݴϴ�.
pair<int, int> point[MAX_N + 1];

// �� �䳢�� id�� �ε��� ��ȣ�� ��ȯ���ݴϴ�.
map<int, int> id_to_idx;

// ������ ���ֿ��� �䳢�� �޷ȴ��� ���θ� ������ݴϴ�.
bool is_runned[MAX_N + 1];

// �ϳ��� ������ ��� �䳢�� ������ ���ϴ� ������ ���ϰ� �ϱ� ����
// total_sum�̶�� ������ �߰����ݴϴ�.
long long total_sum;

// ����ü Rabbit�� ������ �����մϴ�.
struct Rabbit {
    int x, y, j, id;

    // �̵��� �䳢�� �����ϱ� ���� �����Լ��� ������ݴϴ�.
    bool operator <(const Rabbit& b) const {
        if (j != b.j) return j > b.j;
        if (x + y != b.x + b.y) return x + y > b.x + b.y;
        if (x != b.x) return x > b.x;
        if (y != b.y) return y > b.y;
        return id > b.id;
    }
};

// ���� �� ��ġ�� �Ǵ��ϱ� ���� �����Լ��� �ϳ� �� ������ݴϴ�.
bool Cmp(Rabbit a, Rabbit b) {
    if (a.x + a.y != b.x + b.y) return a.x + a.y < b.x + b.y;
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}

// ���� ���� �غ� ������ ó�����ݴϴ�.
void init() {
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> id[i] >> pw[i];
        id_to_idx[id[i]] = i;
        point[i] = make_pair(1, 1);
    }
}

// �䳢�� ���� �̵���ŵ�ϴ�.
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

// �䳢�� �Ʒ��� �̵���ŵ�ϴ�.
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

// �䳢�� �������� �̵���ŵ�ϴ�.
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

// �䳢�� ���������� �̵���ŵ�ϴ�.
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


// ���ָ� �����մϴ�.
void start_round() {
    int k, bonus;
    cin >> k >> bonus;
    priority_queue <Rabbit> rabbit_pq;

    for (int i = 1; i <= p; i++) {
        is_runned[i] = false;
    }

    // �켱 p������ �䳢���� ���� priority queue�� �־��ݴϴ�.
    for (int i = 1; i <= p; i++) {
        Rabbit new_rabbit;
        new_rabbit.x = point[i].first;
        new_rabbit.y = point[i].second;
        new_rabbit.j = jump_cnt[i];
        new_rabbit.id = id[i];

        rabbit_pq.push(new_rabbit);
    }

    // ���ָ� kȸ �����մϴ�.
    while (k--) {
        // �켱������ ���� ���� �䳢�� priority queue���� �̾ƿɴϴ�.
        Rabbit cur_rabbit = rabbit_pq.top(); rabbit_pq.pop();

        // �ش� �䳢�� ��, ��, ��, �� 4���� �������� �̵���ŵ�ϴ�.
        // ������ �������� �̵���Ų �� ���� ��ġ�� ���ϰ�
        // ���� ���������κ��� �ָ� �ִ� ��ġ�� ã���ݴϴ�.
        int dis = pw[id_to_idx[cur_rabbit.id]];
        Rabbit nex_rabbit = cur_rabbit;
        nex_rabbit.x = 0;
        nex_rabbit.y = 0;


        // �䳢�� ���� �̵���ŵ�ϴ�.
        Rabbit up_rabbit = GetUpRabbit(cur_rabbit, dis);
        // ���ݱ����� �������麸�� �� �ָ� �� �� �ִٸ� �������� �����մϴ�.
        if (Cmp(nex_rabbit, up_rabbit)) nex_rabbit = up_rabbit;


        // �䳢�� �Ʒ��� �̵���ŵ�ϴ�.
        Rabbit down_rabbit = GetDownRabbit(cur_rabbit, dis);
        // ���ݱ����� �������麸�� �� �ָ� �� �� �ִٸ� �������� �����մϴ�.
        if (Cmp(nex_rabbit, down_rabbit)) nex_rabbit = down_rabbit;


        // �䳢�� �������� �̵���ŵ�ϴ�.
        Rabbit left_rabbit = GetLeftRabbit(cur_rabbit, dis);
        // ���ݱ����� �������麸�� �� �ָ� �� �� �ִٸ� �������� �����մϴ�.
        if (Cmp(nex_rabbit, left_rabbit)) nex_rabbit = left_rabbit;


        // �䳢�� ���������� �̵���ŵ�ϴ�.
        Rabbit right_rabbit = GetRightRabbit(cur_rabbit, dis);
        // ���ݱ����� �������麸�� �� �ָ� �� �� �ִٸ� �������� �����մϴ�.
        if (Cmp(nex_rabbit, right_rabbit)) nex_rabbit = right_rabbit;


        // �䳢�� ���� Ƚ���� �������ְ�, priority queue�� �ٽ� ����ֽ��ϴ�.
        nex_rabbit.j++;
        rabbit_pq.push(nex_rabbit);

        // ���� point, jump_cnt �迭���� ���� �������ݴϴ�.
        int nex_idx = id_to_idx[nex_rabbit.id];
        point[nex_idx] = make_pair(nex_rabbit.x, nex_rabbit.y);
        jump_cnt[nex_idx]++;

        // �䳢�� �޷ȴ��� ���θ� üũ���ݴϴ�.
        is_runned[nex_idx] = true;

        // �䳢�� �޴� ������ (���� �� �䳢)�� (r + c)��ŭ ������ ���ְ�,
        // ��� �䳢(total_sum)���� (r + c)��ŭ ������ �����ݴϴ�.
        // ���������� i�� �䳢�� �޴� ������ result[i] + total_sum�� �˴ϴ�.
        result[nex_idx] -= (nex_rabbit.x + nex_rabbit.y);
        total_sum += (nex_rabbit.x + nex_rabbit.y);
    }

    // ���ʽ� ������ ���� �䳢�� ã���ϴ�.
    // �̹� ���ֶ� �޸� �䳢 �� ���� �ָ��ִ� �䳢�� ã���ϴ�.
    Rabbit bonus_rabbit;
    bonus_rabbit.x = 0;
    bonus_rabbit.y = 0;
    while (!rabbit_pq.empty()) {
        Rabbit cur_rabbit = rabbit_pq.top(); rabbit_pq.pop();

        // �޸��� ���� �䳢�� ��ŵ�մϴ�.
        if (!is_runned[id_to_idx[cur_rabbit.id]]) continue;

        if (Cmp(bonus_rabbit, cur_rabbit))
            bonus_rabbit = cur_rabbit;
    }

    // �ش� �䳢���� bonus��ŭ ������ �߰����ݴϴ�.
    result[id_to_idx[bonus_rabbit.id]] += bonus;
}

// �̵��Ÿ��� �����մϴ�.
void power_up() {
    int id, t;
    cin >> id >> t;
    int idx = id_to_idx[id];

    pw[idx] *= t;
}

// �ְ��� �䳢�� �����մϴ�.
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
        // ���� ���� �غ� ������ ó�����ݴϴ�.
        if (query == 100) {
            init();
        }
        // ���ָ� �����մϴ�.
        if (query == 200) {
            start_round();
        }
        // �̵��Ÿ��� �����մϴ�.
        if (query == 300) {
            power_up();
        }
        // �ְ��� �䳢�� �����մϴ�.
        if (query == 400) {
            print_result();
        }
    }
}