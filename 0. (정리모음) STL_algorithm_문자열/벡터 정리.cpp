/* https://blockdmask.tistory.com/70
* vector container ��?
* - �ڵ����� �޸𸮰� �Ҵ�Ǵ� �迭, 
* - �ε��� �����Ͽ� �� ���� ����
* - �Լ��� �����ÿ��� �����ڸ� ����ؾ� �ּҸ� ����, ���� ���� ����. ����, �ð� ���⵵�� O(N) -> O(1)�� �پ��.
* - template�� ����ϱ� ������ ������ Ÿ���� ������� ���� �� ����. 
* - vector.push_back(��) : ���� ���� �� �������� �߰���. (append)
* - vector.pop_back() : ������ ���Ҹ� ����.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void print_func(string name, vector<int>& v) {
	cout << name << " : ";
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << "\n";
}

int main() {
	// �������� �ڷ��� ���� ����.
	/*vector<int> v1;
	vector<double> v2;
	vector<string> v3;
	vector<char> v4;*/

	//// string ����, ���ڿ��� ���� ���� �ϳ��� �ε����� ��. python ����Ʈ ����. ��¾��.
	//v3.push_back("sejun");
	//cout << v3[0] << "\n";

	vector<int> v1(5); // �⺻��(0)���� �ʱ�ȭ �� 5���� ���Ҹ� ������ vector v�� ����.
	print_func("v1", v1);

	vector<int> v2(5, 2); // 2�� �ʱ�ȭ�� 5���� ���Ҹ� ������ vector v�� ����.
	print_func("v2", v2);
	
	vector<int> v3(v2);  // v3�� v2 vector�� �����ؼ� ����. 
	print_func("v3", v3);

	if (v1 == v3) cout << 1;  // ��Һ񱳴� ������(==)�� ����ϴ°� ���� ��. -> ��� ���� ������ ������ ��Ÿ��. 

	v1.assign(4, 2);  // ���Ӱ� �Ҵ��
	print_func("v1.assing(5,2)", v1);

	v2.assign(3, 10);  // ���Ӱ� �Ҵ��
	print_func("v2.assing(3,10)", v2);
	
	v2.front(); // ù��° ���Ҹ� ����.
	v2.back(); // ������ ���Ҹ� ����.

	// v2.clear(); // ��� ���Ҹ� ����. ���Ҹ� �����ϰ� �޸𸮴� ���� ����. size�� �پ��� capacity�� �״��.

	v2.push_back(7);  // ������ ���� �ڿ� 7 ����. append
	print_func("v2.push_back(7)", v2);
	v2.pop_back();  // ������ ���Ҹ� ����.
	print_func("v2.pop_back()", v2);

	v2.begin();  // ù��° ���Ҹ� ����Ŵ (iterator�� ���)
	v2.end();  // �������� "����"�� ����Ŵ (iterator�� ���)

	v2.rbegin();  // reverse begin�� ����Ŵ (�Ųٷ� �ؼ� ù��° ���Ҹ� ����Ŵ) (iterator�� ���)
	v2.rend();  // reverse end�� ����Ŵ (�Ųٷ� �ؼ� �������� ������ ����Ŵ) (iterator�� ���)

	v2.resize(2);  // ũ�⸦ n���� ����, �� �۾����� ��� �ڿ� ������ ������, �� Ŀ���� ��� default ���� 0���� �ʱ�ȭ
	print_func("v2.resize(10)", v2);
	
	v2.resize(10, 20);  // ũ�⸦ n���� ����, �� Ŀ���� ��� 20���� �ʱ�ȭ �Ѵ�. 
	print_func("v2.resize(10,20)", v2);

	v2.size(); // ������ ������ ����
	cout << "v2.size()" << v2.size() << "\n";

	v2.capacity(); // �Ҵ�� ������ ũ�⸦ ����
	cout << "v2.capacity()" << v2.capacity() << "\n";

	v2.swap(v3); // v1�� v2�� ���ҿ� capacity �ٲ��� (��� ���� ����)
	print_func("v2 swap with v3", v2);
	print_func("v3 swap with v2", v3);

	print_func("before v2.insert(v2.begin(), -1, 4)", v2);
	v2.insert(v2.begin(), 3, -1);  // v2 ���� �κп� 3���� -1�� ���� ����, ���� ������ �ڷ� �и���.
	print_func("v2.insert(v2.begin(), -1, 4)", v2);

	v2.insert(v2.begin() + 2, 2, 10);  // v2.begin()+2 �ε������� ����.
	print_func("v2.insert(v2.begin()+2, 2, 10)", v2);

	cout <<"before erase v2.capacity() : " << v2.capacity() << "\n";
	v2.erase(v2.begin()+2);  // iter ��ġ�� ������, size�� �ٰ� capacity(�Ҵ�� �޸�)�� �״�� ���� ����. 
	print_func("v2.erase(v2.begin()+2)", v2);
	cout << "after erase v2.capacity() : " << v2.capacity() << "\n";

	v2.erase(v2.begin(), v2.begin() + 2);  // iter�� ������ ������. ���� �״�� capacity�� ���� ����.
	print_func("v2.erase(v2.begin(), v2.begin() + 2)", v2);

	v2.empty(); // vector�� size�� ��� ������ ���� 1 else 0. capacity�ʹ� ��� ����.
	cout << "v2.empty() : " << v2.empty() << "\n";
	
	//sort(v2.begin(), v2.end()); // �������� ����
	//reverse(v2.begin() + 2, v2.end() + 4);  // �������� ����, index 2~3����.

	int max = *max_element(v2.begin(), v2.end());  // ���� ū ���� ��ȯ��
	int max_index = max_element(v2.begin(), v2.end()) - v2.begin();  // ���� ū �ε����� ��ȯ��(�ε�����ȣ ��ȯ)

	// vector�� iterator�� �ݺ��� �� ����.
	for (int e : v2) {  // v2�� �� ���ҵ��� ��ȸ�ϸ鼭 ���� �����Ͽ� ����
		cout << e << " ";
	}
	for (int& e : v2) {  // v2�� �����ϱ� ������, e�� ����� ���� v2�� �����
		e = 1;
	}
	for (int e : v2) cout << e << " ";
}