#include<iostream>
#include<queue>
using namespace std;

struct Rabbit {
    int x, y, j, id;

    // ������ operator�ν� True or False ��ȯ
    // �켱���� ť�� �ְ� �Ǹ�, �Ʒ� ������ �����ϴ� ���� ū ��(True)�� root�� �ø��� �ȴ�.
    bool operator <(const Rabbit& b) const { 
        // �켱���� : j > x+y > x > y > id
        if (j != b.j) return j > b.j;
        if (x + y != b.x + b.y) return x + y > b.x + b.y;
        if (x != b.x) return x > b.x;
        if (y != b.y) return y > b.y;
        return id > b.id;
    }
};

// �� ���� ����ü�� �����ͼ� ���ǿ� ���� �񱳸� ���� ��, True or False ��ȯ
bool Cmp(Rabbit a, Rabbit b) {
    // �켱���� : x+y > x > y > id
    if (a.x + a.y != b.x + b.y) return a.x + a.y < b.x + b.y;
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // �켱���� ť ����
    priority_queue<Rabbit> PQ;

    // ����ü ���� �� �� �Ҵ�
    Rabbit new_rabbit;
    new_rabbit.x = 1;
    new_rabbit.y = 2;
    new_rabbit.j = 3;
    new_rabbit.id = 53;

    // �켱���� ť�� ����ü push -> Ʈ���� �� ���� ����ü ���� ����
    // ��, ����ü�� ���ǿ� ���� �켱���� ť(max heap)�� �ȴ�.
    PQ.push(new_rabbit);

    // ����ü 
    Rabbit cur_rabbit = PQ.top(); // max ����ü ��������
    PQ.pop(); // max ����ü ����

    Rabbit nex_rabbit; // ���ο� rabit ����
    nex_rabbit.x = 8;
    nex_rabbit.y = 3;
    nex_rabbit.j = 4;
    nex_rabbit.id = 23;

    // Cmp ���ǿ� ���� ����ü�� ���Ͽ� True�� ����
    if (Cmp(cur_rabbit, nex_rabbit)) nex_rabbit = cur_rabbit;

}