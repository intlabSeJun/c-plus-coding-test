/*
우선순위 큐는 pop을 할 때 가장 우선순위가 높은 원소가 나오는 큐

< 단순 배열로 구현시 >
1. 원소의 추가가 O(1)
2. 우선순위가 가장 높은 원소의 확인 O(N)
3. 우선순위가 가장 높은 원소의 제거가 O(N)

< 힙 이라는 구조를 이용시 >
1. 원소의 추가가 O(lgN)
2. 우선순위가 가장 높은 원소의 확인 O(1)
3. 우선순위가 가장 높은 원소의 제거가 O(lgN)

< 힙은 무엇일까? +최소 힙, 최대 힙 >
힙은 이진트리 구조를 가지고 있음. 
하지만, 이진 검색 트리와는 다르다. 
힙은 최대값 혹은 최솟값을 찾기 위해 사용할 수 있음. (최대 힙, 최소 힙)
최소 힙 : 루트가 가장 작은 값. + 부모 노드가 자식 노드보다 작아야 함.
또한, 높이가 같은 곳부터 차례대로 채워지기 때문에 트리의 불균형이 발생하지 않음.

< 힙의 정리 과정 >
부모 노드와 비교해서 정렬됨.
즉, 최대 트리 높이만큼만 비교하면 됨.
균향 트리이기 때문에 삽입의 시간 복잡도는 O(lgN)이다.

< 최소값(루트) 삭제 과정 >
트리의 가장 마지막 값과의 자리를 바꾸고 나서, 최소값 제거함.
그리고 힙의 성질이 만족될 수 있게 내부적으로 노드의 위치를 바꾼다. 

< prioirty_queue에서 할 수 있는건 어차피 set에서도 할 수 있고, 시간 복잡도도 동일하다.
그러면 set이 제공하는 기능이 더 많은데 priority_queue를 쓸 이유가 있나요? >
맞는 말이지만, priority_queue가 더 수행 속도가 빠르고, 공간도 적게 차지합니다.
set은 불균형에 대한 처리가 필요하기 때문에 그렇다.

*/

// 구조체를 활용한 우선순위 큐 풀이.
//#include<iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//struct node {
//	int x;
//
//	bool operator<(const node& a) const {
//		if (abs(x) != abs(a.x)) return abs(a.x) < abs(x);
//		return a.x < x;
//	}
//};
//
//priority_queue<node> PQ;
//int N;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N;
//
//	int x;
//	for (int i = 0; i < N; i++) {
//		cin >> x;
//		node x_node;
//		x_node.x = x;
//
//		if (x == 0) {
//			if (PQ.empty()) cout << 0 << "\n";
//			else {
//				cout << PQ.top().x << "\n";
//				PQ.pop();
//			}
//		}
//		else PQ.push(x_node);
//	}
//}

// class를 활용한 우선순위 큐 풀이
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N;

class cmp {
public:
	bool operator() (int a, int b) {  // b가 루트노드 
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
		//return a > 0 && b < 0;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	priority_queue<int, vector<int>, cmp> PQ;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (PQ.empty()) cout << 0 << "\n";
			else {
				cout << PQ.top() << "\n";
				PQ.pop();
			}
		}
		else PQ.push(x);
	}

}