/*
STL list.cpp 파일에 정리된 사용법들을 참고하여 예시 돌려보기
*/
#include<iostream>
#include<list>
#include<string>
using namespace std;

void print_func(list<int> &L, string name) {
	cout << name << " : ";
	for (int e : L) cout << e <<" ";
	cout << "\n";
}
int main() {
	list<int> L;
	for (int i = 0; i < 10; i++) L.push_back(i);
	print_func(L, "push_back");

	// insert + next 예제 
	L.insert(next(L.begin(),2), 3);  // L.begin에서 2만큼 next한 지점에 3을 insert함. 오른쪽으로 한칸씩 밀려남 
	print_func(L, "insert");

	// erase + next
	L.erase(next(L.begin(), 2));  // L.begin의 2만큼 next한 지점의 값을 지운다. 왼쪽으로 한칸씩 밀려남
	print_func(L, "erase + next");

	// size()
	cout << L.size() << "\n";

	//remove
	L.push_back(0);  // 0 삽입
	L.remove(0);  // 0 모두 제거
	print_func(L, "remove");

	//remove_if
	L.remove_if([](int x) {return x % 2 == 0; }); // 짝수만 제거함
	print_func(L, "remove_if");

	// list to list
	list<int> L_plus;
	L_plus.push_back(123);
	print_func(L_plus, "L_plus.push_back");
	cout << L_plus.size() << "\n";  // 1

	// L.splice(iter,container) // L의 iter에서부터 container의 주소를 갖다 붙임. 전체 container가 연결된다. 
	L.splice(L.end(), L_plus);  // 주소를 옮겨 담는다. L.end()는 다음 주소를 카리키는데 이를 L_plus로 가르키게 한다. 
	cout << L_plus.size() << "\n";  // 0
	print_func(L, "L.splice(L.end(), L_plus)");

	list<int> L2 = { 10,11,12,13,14 };
	// L.splice(iter, container, container_iter_index) // L의 iter에서부터 container의 iter_index의 주소를 갖다 붙임.
	L.splice(L.end(), L2, next(L2.begin(), 2));  // L.end()에다가 L2에서 가르키는 원소의 주소를 갖다 붙임.
	print_func(L, "L.splice(L.end(), L2, next(L2.begin(), 2))");
	print_func(L2, "L2 of after splice");  // 위에서 splice한 원소는 L2에서 빠지게 됨. 

	// L.splice(iter, container, container_iter_begin, container_iter_end) // L의 iter에서부터 container의 iter_begin~end까지 갖다 붙임.
	L.splice(L.end(), L2, next(L2.begin(),2), L2.end()); 
	print_func(L, "L.splice(L.end(), L2, next(L2.begin(),2), L2.end())");

	// sort(오름차순), 내림차순은 sort()->reverse()
	L.sort();
	print_func(L, "L.sort()");

	// swap
	list<int> L3 = { -1,-2,-4 };
	L.swap(L3);
	print_func(L, "L.swap(L3)");

	// unique() 인접한(양옆의) 원소가 같으면 유일하게 만듬(하나만 빼고 삭제), set을 하기 위해서는 sort() -> unique()
	list<int> L4 = { 1,1,1,2,2,2,2,2,3,3,3,2,1 };
	L4.unique();
	print_func(L4, "L4.unique()");

	// merge, 두번째 인자로 이항 조건자가 올 수 있음.
	list<int> L5 = { 1,2,3 };
	list<int> L6 = { 4,5,6 };
	L5.merge(L6);  // merge하면 L6는 비워진다.
	cout << L5.size() << " " << L6.size() << "\n";


}
/*
list<int> a = { 1,2 }; // list 생성
	list<int>::iterator t = a.begin();  // t는 1을 가르킴
	a.push_front(10);  // 10 1 2
	cout << *t << '\n';  // t가 가르키는 값 = 1을 출력
	a.push_back(5); // 10 1 2 5
	a.insert(t, 6);  // t가 가르키는 곳 앞에 6을 삽입, 10 6 1 2 5
	t++;  // t를 1칸 앞으로 전진, 현재 t가 가르키는 값은 2
	t = a.erase(t);   // t가 가르키는 값을 제거, 그 다음 원소인 5의 위치를 반환
					  // 10 6 1 5,
	cout << *t << "\n";
	for (auto i : a) cout << i << " ";
	cout << "\n";
	for (list<int>::iterator it = a.begin(); it != a.end(); it++) cout << *it << " "; // iterator 시작부터 값을 가르킴

	a.front(); // 맨 앞의 원소를 반환, 참조
	a.back();  // 맨 뒤의 원소를 반환, 참조
	a.begin();  // 맨 앞의 원소를 가리키는 iteraotr를 반환
	a.end();  // 맨 마지막의 다음 원소를 가리키는 iterator를 반환
	a.rbegin();  // 뒤에서부터 순차적으로 접근할 때 사용, 뒤집었을 때 첫번째
	a.rend();  // 뒤에서부터 순차적으로 접근할 때 사용, 뒤집어졌을 때 마지막
	a.push_back(5);  // 꼬리로 5를 삽입
	a.push_front(5);  // 머리로 원소 삽입
	a.pop_back();  // 마지막 원소 제거
	a.pop_front();  // 맨 앞의 원소 제거
	a.insert(iter, k);  // iter가 가리키는 위치에 원소 압입, 삽입한 원소를 가리키는 iterator 반환, 삽입하면 나머지들은 뒤로 밀림 (왼쪽에 삽입됨)
	a.erase(iter);  // iter가 가리키는 원소를 삭제, 삭제한 원소의 다음 원소를 가리키는 iterator 반환
	a.size();  // 원소의 개수 반환
	a.remove(k);  // k와 같은 원소를 모두 제거
	a.remove_if(predicate);  // 단항 조건자 predicate에 해당하는 원소를 모두 제거
	a.reverse();  // 원소들의 순차열을 뒤집음.
	a.next(iter, num) // list a에서 iter에 해당하는 지점의 num만큼 next한 지점의 포인터.
*/