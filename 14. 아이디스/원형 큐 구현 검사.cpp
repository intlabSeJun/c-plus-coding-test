#include<iostream>
using namespace std;

int SIZE = 5;

class CircleQueue {
public:
	CircleQueue() {
		for (int i = 0; i < 5; i++) data[i] = 0;
		count = 0; 
		data_size = SIZE;
	}

	bool IsEmpty();
	bool IsFull();
	void push(int t);
	int front();
	int size();
	void pop();

	int front_point = 0, rear_point = -1;
	int data[5];

private:
	//int front_point = 0, rear_point = 0;
	//int data[5];
	int data_size;
	int count;
};

bool CircleQueue::IsEmpty()
{	
	if (count == 0) {
		cout << "The Queue is Empty\n";
		return true;
	}
	else return false;
}

bool CircleQueue::IsFull()
{
	if (count == data_size) {
		cout << "Circle Queue is Full" << "\n";
		return true;
	}
	else return false;
}

void CircleQueue::push(int t)
{
	if (IsFull()) return;

	rear_point = (rear_point+1) % data_size;
	//cout << "rear_point :" << rear_point << "\n";
	data[rear_point] = t;
	count++;
}

int CircleQueue::front()
{
	if (IsEmpty()) return -1;
	else return data[front_point];
}

int CircleQueue::size()
{
	return count;
}

void CircleQueue::pop()
{
	if (IsEmpty()) return;

	front_point = (front_point + 1) % data_size;
	count--;
}


void print_Q_info(CircleQueue& Q) {
	cout << "Q.size():" << Q.size() << " | Q.IsEmpty():" << Q.IsEmpty() << " | Q.IsFull():" << Q.IsFull()
		<< " | Q.front_point:" << Q.front_point << " | Q.rear_point:" << Q.rear_point << "\n";
	cout << "Cur_data: ";
	for (int i = 0; i < 5; i++) cout << Q.data[i] << " ";
	cout << "DataSize: " << Q.size();
	cout << "\n\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	CircleQueue Q;

	cout << "Init status\n";
	print_Q_info(Q);

	cout << "Q.push(1)\n";
	Q.push(1);
	print_Q_info(Q);

	cout << "Q.push(2)\n";
	Q.push(2);
	print_Q_info(Q);

	cout << "Q.pop()\n";
	Q.pop();
	print_Q_info(Q);

	cout << "Q.push(3)\n";
	Q.push(3);
	print_Q_info(Q);

	cout << "Q.push(4)\n";
	Q.push(4);
	print_Q_info(Q);

	cout << "Q.push(5)\n";
	Q.push(5);
	print_Q_info(Q);

	cout << "front and pop\n";
	for (int i = 0; i < 5; i++) {
		cout << "Q.front() :" << Q.front() << " Q.pop()\n";
		Q.pop();
		print_Q_info(Q);
	}

	cout << "push\n";
	for (int i = 0; i < 5; i++) {
		Q.push(i + 10);
		print_Q_info(Q);
	}

	cout << "front and pop\n";
	for (int i = 0; i < 5; i++) {
		cout << "Q.front() :" << Q.front() << " Q.pop()\n";
		Q.pop();
		print_Q_info(Q);
	}

}