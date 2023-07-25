#include<iostream>
#include<vector>
using namespace std;


void change_value(vector<vector<int>> v1, vector<vector<int>>& v2) {
	/*
	 vector<vector<int>> v1  : ���Ͱ� �����. ���� ���� x
	 vector<vector<int>> &v2 : ���� �ּ�. ���� ���� o
	*/
	v1[0][0] = 0; // ���� �ȹٲ�
	v2[0][1] = -1; // ���� �ٲ�
}

void print_vector(vector<vector<int>>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
}

int main() {
	vector<vector<int>> v(2, vector<int>(3)); // (2,3) ��� ����
	cout << v.size() << " " << v[0].size() << "\n"; // 2 3

	print_vector(v); // �ʱⰪ�� 0���� ��.
	vector<vector<int>> v2(2, vector<int>(3, -1)); // �ʱⰪ -1
	print_vector(v2); // -1�� �ʱ�ȭ�� (2,3) 
	for(int i=0;i<v2.size(); i++) // fill()�� ����ؼ� �ʱ�ȭ ����
		fill(v2[i].begin(), v2[i].end(), 7); // �� �ึ�� 7�� �ʱ�ȭ
	print_vector(v2); // 7�� �ʱ�ȭ�� (2,3)

	change_value(v2, v2);
	print_vector(v2); // v[0][1]�� -1�� ����.
}