/*
STL list.cpp ���Ͽ� ������ �������� �����Ͽ� ���� ��������
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

	// insert + next ���� 
	L.insert(next(L.begin(),2), 3);  // L.begin���� 2��ŭ next�� ������ 3�� insert��. ���������� ��ĭ�� �з��� 
	print_func(L, "insert");

	// erase + next
	L.erase(next(L.begin(), 2));  // L.begin�� 2��ŭ next�� ������ ���� �����. �������� ��ĭ�� �з���
	print_func(L, "erase + next");

	// size()
	cout << L.size() << "\n";

	//remove
	L.push_back(0);  // 0 ����
	L.remove(0);  // 0 ��� ����
	print_func(L, "remove");

	//remove_if
	L.remove_if([](int x) {return x % 2 == 0; }); // ¦���� ������
	print_func(L, "remove_if");

	// list to list
	list<int> L_plus;
	L_plus.push_back(123);
	print_func(L_plus, "L_plus.push_back");
	cout << L_plus.size() << "\n";  // 1

	// L.splice(iter,container) // L�� iter�������� container�� �ּҸ� ���� ����. ��ü container�� ����ȴ�. 
	L.splice(L.end(), L_plus);  // �ּҸ� �Ű� ��´�. L.end()�� ���� �ּҸ� ī��Ű�µ� �̸� L_plus�� ����Ű�� �Ѵ�. 
	cout << L_plus.size() << "\n";  // 0
	print_func(L, "L.splice(L.end(), L_plus)");

	list<int> L2 = { 10,11,12,13,14 };
	// L.splice(iter, container, container_iter_index) // L�� iter�������� container�� iter_index�� �ּҸ� ���� ����.
	L.splice(L.end(), L2, next(L2.begin(), 2));  // L.end()���ٰ� L2���� ����Ű�� ������ �ּҸ� ���� ����.
	print_func(L, "L.splice(L.end(), L2, next(L2.begin(), 2))");
	print_func(L2, "L2 of after splice");  // ������ splice�� ���Ҵ� L2���� ������ ��. 

	// L.splice(iter, container, container_iter_begin, container_iter_end) // L�� iter�������� container�� iter_begin~end���� ���� ����.
	L.splice(L.end(), L2, next(L2.begin(),2), L2.end()); 
	print_func(L, "L.splice(L.end(), L2, next(L2.begin(),2), L2.end())");

	// sort(��������), ���������� sort()->reverse()
	L.sort();
	print_func(L, "L.sort()");

	// swap
	list<int> L3 = { -1,-2,-4 };
	L.swap(L3);
	print_func(L, "L.swap(L3)");

	// unique() ������(�翷��) ���Ұ� ������ �����ϰ� ����(�ϳ��� ���� ����), set�� �ϱ� ���ؼ��� sort() -> unique()
	list<int> L4 = { 1,1,1,2,2,2,2,2,3,3,3,2,1 };
	L4.unique();
	print_func(L4, "L4.unique()");

	// merge, �ι�° ���ڷ� ���� �����ڰ� �� �� ����.
	list<int> L5 = { 1,2,3 };
	list<int> L6 = { 4,5,6 };
	L5.merge(L6);  // merge�ϸ� L6�� �������.
	cout << L5.size() << " " << L6.size() << "\n";


}
/*
list<int> a = { 1,2 }; // list ����
	list<int>::iterator t = a.begin();  // t�� 1�� ����Ŵ
	a.push_front(10);  // 10 1 2
	cout << *t << '\n';  // t�� ����Ű�� �� = 1�� ���
	a.push_back(5); // 10 1 2 5
	a.insert(t, 6);  // t�� ����Ű�� �� �տ� 6�� ����, 10 6 1 2 5
	t++;  // t�� 1ĭ ������ ����, ���� t�� ����Ű�� ���� 2
	t = a.erase(t);   // t�� ����Ű�� ���� ����, �� ���� ������ 5�� ��ġ�� ��ȯ
					  // 10 6 1 5,
	cout << *t << "\n";
	for (auto i : a) cout << i << " ";
	cout << "\n";
	for (list<int>::iterator it = a.begin(); it != a.end(); it++) cout << *it << " "; // iterator ���ۺ��� ���� ����Ŵ

	a.front(); // �� ���� ���Ҹ� ��ȯ, ����
	a.back();  // �� ���� ���Ҹ� ��ȯ, ����
	a.begin();  // �� ���� ���Ҹ� ����Ű�� iteraotr�� ��ȯ
	a.end();  // �� �������� ���� ���Ҹ� ����Ű�� iterator�� ��ȯ
	a.rbegin();  // �ڿ������� ���������� ������ �� ���, �������� �� ù��°
	a.rend();  // �ڿ������� ���������� ������ �� ���, ���������� �� ������
	a.push_back(5);  // ������ 5�� ����
	a.push_front(5);  // �Ӹ��� ���� ����
	a.pop_back();  // ������ ���� ����
	a.pop_front();  // �� ���� ���� ����
	a.insert(iter, k);  // iter�� ����Ű�� ��ġ�� ���� ����, ������ ���Ҹ� ����Ű�� iterator ��ȯ, �����ϸ� ���������� �ڷ� �и� (���ʿ� ���Ե�)
	a.erase(iter);  // iter�� ����Ű�� ���Ҹ� ����, ������ ������ ���� ���Ҹ� ����Ű�� iterator ��ȯ
	a.size();  // ������ ���� ��ȯ
	a.remove(k);  // k�� ���� ���Ҹ� ��� ����
	a.remove_if(predicate);  // ���� ������ predicate�� �ش��ϴ� ���Ҹ� ��� ����
	a.reverse();  // ���ҵ��� �������� ������.
	a.next(iter, num) // list a���� iter�� �ش��ϴ� ������ num��ŭ next�� ������ ������.
*/