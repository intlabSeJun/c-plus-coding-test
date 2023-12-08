#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* nextNode; // 다음 노드
	Node* prevNode; // 이전 노드
	Node* last; // 마지막 노드
};

Node* init(Node* temp) { // 초기화
	temp = new Node();
	temp->nextNode = NULL;
	temp->prevNode = NULL;
	temp->data = 0;
	return temp;
}

Node* insert(Node* head, int data) {
	if (head == NULL) {// 첫번째 삽입인 경우 
		head = init(head);
		head->data = data;
		head->last = head;
		return head;
	}

	Node* currentNode = head->last;
	Node* newNode = NULL;
	newNode = init(newNode);
	newNode->data = data;
	newNode->prevNode = currentNode;
	currentNode->nextNode = newNode;
	head->last = newNode;
	return head;
}

int getData(Node* head, int index) {
	Node* currentNode = head;
	for (int i = 0; i < index && currentNode != NULL; i++) {
		currentNode = currentNode->nextNode;
	}
	if (currentNode == NULL) {
		return -1;//size를 넘겼을 경우 
	}
	return currentNode->data;
}

Node* remove(Node* head, int index) {//index번째 노드 삭제 
	Node* currentNode = head;
	Node* prevNode = NULL;//이전 노드
	for (int i = 0; i < index && currentNode != NULL; i++) {
		prevNode = currentNode;
		currentNode = currentNode->nextNode;
		if (currentNode == NULL) {//인덱스가 사이즈를 넘겼을 경우
			return head;
		}
		if (prevNode == NULL) {// 루트 노드를 삭제하는 경우
			head->nextNode->last = head->last;
			head = head->nextNode;
		}
		if (currentNode->nextNode == NULL) {//마지막 노드 삭제
			head->last = prevNode;
			prevNode->nextNode = NULL;
		}
		prevNode->nextNode = currentNode->nextNode;
		currentNode->nextNode->prevNode = prevNode;
		return head;
	}
}

void print(Node* currentNode) { // 출력
	while (currentNode != NULL) {
		cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}
	cout << endl;
	return;
}

int main() {
	Node* list = NULL;
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 4);
	list = insert(list, 5);
	list = insert(list, 6);
	list = insert(list, 7);
	list = insert(list, 8);

	print(list);

	list = remove(list, 3);
	print(list);
	list = insert(list, 700);
	print(list);
}