#include<iostream>
#include<tuple>
using namespace std;
#include<string>
int main() {
	/* 1. tuple �ʱ�ȭ*/
	tuple<int, int, int> t(1, 2, 3); //����� ���ÿ� �ʱ�ȭ

	tuple<int, int> t2; // ����
	t2 = make_tuple(1, 2); // �ʱ�ȭ

	/* 2. tuple ���� ����
	   - get�̿�
	   - ����� �����ؾ� �� */ 
	cout << get<0>(t) << get<1>(t) << get<2>(t);

	for (int i = 0; i < 3; i++) cout << get<i>(t) << " "; //error

	int const a = 1;
	cout << get<a>(t); // okay

	/* 3. tuple ���Һ���
	   - tie() �̿�.
	   - ���� �ڷ����� ��. */
	tuple<int, int, int> t3;
	t3 = make_tuple(1, 3, 2);
	int x, y, z;
	tie(x, y, z) = t3;  // x=1,y=3,z=2

	tuple<int, char> t4(1, 'a');
	int a;
	char b;
	tie(a, b) = t4; // error
	
	/* 4.�� ���� Ʃ�� ����*/
	tuple<int, int> t5(1, 2);
	tuple<int, int> t6(3, 4);
	tuple<int, int, int, int> t7 = tuple_cat(t5, t6);


	/* 5. tuple swap*/
	t5.swap(t6);
}