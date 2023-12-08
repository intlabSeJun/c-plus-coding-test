#include<iostream>
using namespace std;

int SIZE = 5;

class CircleQueue {
public:
	CircleQueue() {  // ������, �ʱ�ȭ
		for (int i = 0; i < 5; i++) data[i] = 0;
		count = 0;
		data_size = SIZE;
		front_point = 0;
		rear_point = -1;
	}

	// �Լ� �����
	bool IsEmpty();  // ���� ť ��� �ִ��� Ȯ��
	bool IsFull();  // ���� ť �� ���ִ��� Ȯ��
	void push(int t);  // ���� ť�� ������ �Է�
	int front();  // ���� ť front�� ��ȯ
	int size();  // ���� ť ������ ������
	void pop();  // ���� ť front �� ����

private:
	int front_point, rear_point;  // ���� ť �հ� ���� ��ġ �ε���, �� ���̿��� -1 ���̷�.
	int data[5];  // ���� ť ���� ���� �迭
	int data_size;  // �����͸� ���� �� �ִ� �ִ� ũ��
	int count;  // ������� ���� ������ ũ��
};

bool CircleQueue::IsEmpty()  // ���� ť ��� �ִ��� Ȯ��
{
	if (count == 0) {  // ��� �ִٸ�
		cout << "The Queue is Empty\n";
		return true;
	}
	else return false;
}

bool CircleQueue::IsFull()  // ���� ť �� ���ִ��� Ȯ��
{
	if (count == data_size) {  // ���� ������ ����
		cout << "Circle Queue is Full" << "\n";
		return true;
	}
	else return false;
}

void CircleQueue::push(int t)  // ���� ť�� ������ �Է�
{
	if (IsFull()) return;  // �� �� ������ return

	rear_point = (rear_point + 1) % data_size;  // push�� �ε��� ����
	data[rear_point] = t;  // ������ ����
	count++;  // �� ���� ++
}

int CircleQueue::front()  // ���� ť front�� ��ȯ
{
	if (IsEmpty()) return -1;  // ��� �ִٸ� -1 ��ȯ
	else return data[front_point];  // front �� ��ȯ
}

int CircleQueue::size()  // ���� ť ������ ������
{
	return count;  // ���� �� ������ ���� ��ȯ
}

void CircleQueue::pop()  // ���� ť front �� ����
{
	if (IsEmpty()) return;  // ��� �ִٸ� ��ȯ

	front_point = (front_point + 1) % data_size;  // front �ε��� 
	count--;  // �� ����--
}

