/*
* ���� 3
* N�� �������̸� 1�� ��ȯ�ϰ� �������� �ƴϸ� 0�� ��ȯ�ϴ� �Լ� func3(int N)�� �ۼ��϶�.
* N�� 10�� ������ �ڿ����̴�.
* 
* ��� ����
* func3(9) = 1,
* func3(693953651) = 0,
* func3(756580036) = 1
*/
# include <iostream>
# include <math.h>
# include <time.h>

using namespace std;


double m_sqrt(double n)  // custom sqrt, ���� sqrt�� �ӵ� �����. 
{
	double s = 0;
	double t = 0;

	s = n / 2;
	for (; s != t;)
	{
		t = s;
		s = ((n / t) + t) / 2;
	}
	return s;
}

int func3(int num)  // �ӵ��� ��������, sqrt ������ ���ؼ��� �𸥴�.
{
	//int a = sqrt(num);  // ���� sqrt
	int a = m_sqrt(num);  // custom sqrt
	if (a * a == num) {
		return 1;
	}
	else {
		return 0;
	}

}

int func3_1(int num) // �ӵ��� �� �����ɸ��� �뷫 560��.
{
	for (int i = 1; i * 1 <= num; i++) {
		if (i * i == num) return 1;
	}
	return 0;
}

int main() {
	clock_t start, end;
	double duration;
	start = clock();
	int arr[] = { 9, 693953651, 756580036 };
	int out;
	int length_arr = sizeof arr / sizeof arr[0];
	for (int i = 0; i < length_arr; i++) {
		cout << "func3(" << arr[i] << ") = " << func3(arr[i]) << endl;
	}
	end = clock();
	duration = (double)(end-start);
	cout << duration << endl;
}