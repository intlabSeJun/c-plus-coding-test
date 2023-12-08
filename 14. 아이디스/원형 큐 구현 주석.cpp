#include<iostream>
using namespace std;

int SIZE = 5;

class CircleQueue {
public:
	CircleQueue() {  // 생성자, 초기화
		for (int i = 0; i < 5; i++) data[i] = 0;
		count = 0;
		data_size = SIZE;
		front_point = 0;
		rear_point = -1;
	}

	// 함수 선언부
	bool IsEmpty();  // 원형 큐 비어 있는지 확인
	bool IsFull();  // 원형 큐 꽉 차있는지 확인
	void push(int t);  // 원형 큐에 데이터 입력
	int front();  // 원형 큐 front값 반환
	int size();  // 원형 큐 데이터 사이즈
	void pop();  // 원형 큐 front 값 제거

private:
	int front_point, rear_point;  // 원형 큐 앞과 뒤의 위치 인덱스, 둘 사이에는 -1 차이로.
	int data[5];  // 원형 큐 담을 선형 배열
	int data_size;  // 데이터를 담을 수 있는 최대 크기
	int count;  // 현재까지 담은 데이터 크기
};

bool CircleQueue::IsEmpty()  // 원형 큐 비어 있는지 확인
{
	if (count == 0) {  // 비어 있다면
		cout << "The Queue is Empty\n";
		return true;
	}
	else return false;
}

bool CircleQueue::IsFull()  // 원형 큐 꽉 차있는지 확인
{
	if (count == data_size) {  // 꽉차 있으면 수행
		cout << "Circle Queue is Full" << "\n";
		return true;
	}
	else return false;
}

void CircleQueue::push(int t)  // 원형 큐에 데이터 입력
{
	if (IsFull()) return;  // 꽉 차 있으면 return

	rear_point = (rear_point + 1) % data_size;  // push할 인덱스 선택
	data[rear_point] = t;  // 데이터 저장
	count++;  // 총 개수 ++
}

int CircleQueue::front()  // 원형 큐 front값 반환
{
	if (IsEmpty()) return -1;  // 비어 있다면 -1 반환
	else return data[front_point];  // front 값 반환
}

int CircleQueue::size()  // 원형 큐 데이터 사이즈
{
	return count;  // 현재 총 데이터 개수 반환
}

void CircleQueue::pop()  // 원형 큐 front 값 제거
{
	if (IsEmpty()) return;  // 비어 있다면 바환

	front_point = (front_point + 1) % data_size;  // front 인덱스 
	count--;  // 총 개수--
}

