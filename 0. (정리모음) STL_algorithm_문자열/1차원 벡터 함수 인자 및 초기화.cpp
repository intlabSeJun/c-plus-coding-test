#include<iostream>
#include<vector>
using namespace std;


void change_vector_value(vector<int> v1, vector<int> &v2) {
	/*
	 vector<int> v1  : vector���� �����. (+�޸�)
	 vector<int> &v1 : vector���� �ּҰ� �����. (��������)
	*/
	v1[0] = 3; // ������ �ݿ� �ȵ�.
	v2[1] = 4; // ������ �ݿ���.
}

void print_vector(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n";
}

int main() {
	vector<int> v1;  
	print_vector(v1); // ��� �ִ� ����

	vector<int> v2(3, -1); // -1�� 3�� ���� �Ҵ���
	print_vector(v2); // -1 -1 -1

	change_vector_value(v2, v2);
	print_vector(v2);  // -1 4 -1

}