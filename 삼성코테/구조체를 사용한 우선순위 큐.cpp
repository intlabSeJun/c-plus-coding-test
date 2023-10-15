#include<iostream>
#include<queue>
using namespace std;

struct Rabbit {
    int x, y, j, id;

    // 연산자 operator로써 True or False 반환
    // 우선순위 큐에 넣게 되면, 아래 조건을 만족하는 가장 큰 값(True)를 root로 올리게 된다.
    bool operator <(const Rabbit& b) const { 
        // 우선순위 : j > x+y > x > y > id
        if (j != b.j) return j > b.j;
        if (x + y != b.x + b.y) return x + y > b.x + b.y;
        if (x != b.x) return x > b.x;
        if (y != b.y) return y > b.y;
        return id > b.id;
    }
};

// 두 개의 구조체를 가져와서 조건에 따른 비교를 수행 후, True or False 반환
bool Cmp(Rabbit a, Rabbit b) {
    // 우선순위 : x+y > x > y > id
    if (a.x + a.y != b.x + b.y) return a.x + a.y < b.x + b.y;
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 우선순위 큐 생성
    priority_queue<Rabbit> PQ;

    // 구조체 생성 및 값 할당
    Rabbit new_rabbit;
    new_rabbit.x = 1;
    new_rabbit.y = 2;
    new_rabbit.j = 3;
    new_rabbit.id = 53;

    // 우선순위 큐에 구조체 push -> 트리의 각 노드는 구조체 형태 가짐
    // 즉, 구조체의 조건에 따른 우선순위 큐(max heap)이 된다.
    PQ.push(new_rabbit);

    // 구조체 
    Rabbit cur_rabbit = PQ.top(); // max 구조체 가져오기
    PQ.pop(); // max 구조체 제거

    Rabbit nex_rabbit; // 새로운 rabit 생성
    nex_rabbit.x = 8;
    nex_rabbit.y = 3;
    nex_rabbit.j = 4;
    nex_rabbit.id = 23;

    // Cmp 조건에 따른 구조체를 비교하여 True면 수행
    if (Cmp(cur_rabbit, nex_rabbit)) nex_rabbit = cur_rabbit;

}