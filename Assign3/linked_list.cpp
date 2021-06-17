#include "linked_list.h"

#include <iostream>
#include <random>

using namespace std;

bool Append(int data) {
  Node* next = new Node;
  next->data = data;
  next->next = NULL;
  if (HEAD == nullptr) {
    HEAD = next;
    TAIL = HEAD;
  } else {
    TAIL->next = next;
    TAIL = TAIL->next;
  }
  numOfNodes++;
  return true;
}

bool Insert(int idx, int data) {
  if (idx < 0 || idx > numOfNodes) return false;
  // 삽입할 노드
  Node* temp = new Node;
  temp->data = data;
  // 탐색에 쓰일 노드
  Node* cur = HEAD;
  // 해당 index의 노드 전까지 이동
  for (int i = 0; i < idx - 1; i++) cur = cur->next;
  // 만약 마지막 노드에 새로운 노드를 삽입할 경우 tail을 업데이트 해야함
  if (idx == numOfNodes) TAIL = temp;
  // 삽입
  temp->next = cur->next;
  cur->next = temp;
  numOfNodes++;
  return true;
}

void Traverse() {
  Node* temp = HEAD;
  for (int i = 0; i < numOfNodes; i++) {
    cout << temp->data << "\n";
    temp = temp->next;
  }
  cout << "\n";
}

bool Remove(int idx) {
  if (idx < 0 || idx > numOfNodes) return false;
  Node* cur = HEAD;
  if (idx == 0) {
    HEAD = HEAD->next;
    delete cur;
  } else {
    Node* tmp;
    // 해당 위치 이전 노드로 이동
    for (int i = 0; i < idx - 1; i++) cur = cur->next;
    // 단 맨 마지막 노드를 없앨경우 tail을 이전 노드로 바꿔줘야함
    if (idx == numOfNodes - 1) TAIL = cur;
    tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
  }
  numOfNodes--;
  return true;
}

void Reverse() {
  TAIL = NULL;
  // Reverse안된 Linked List의 첫번째 노드를 저장
  Node* cur;
  // 나중에 Reverse된 List의 TAIL을 지정하기 위한 포인터 노드
  Node* tempHEAD = HEAD;
  while (HEAD != NULL) {
    // Reverse하기 전 HEAD의 다음번 노드를 cur에 저장한다.
    cur = HEAD->next;
    // Reverse되지 않은 노드의 가장 첫번째와 Reverse된 노드를 붙인다
    HEAD->next = TAIL;
    // 붙여진 Reversed List의 HEAD를 TAIL에 넣어준다
    TAIL = HEAD;
    // HEAD를 다시 Reverse되지 않은 노드의 가장 첫번째로 옮긴다
    HEAD = cur;
  }
  // TAIL을 HEAD로 옮겨준다(List가 Reverse되었기 때문)
  HEAD = TAIL;
  // 처음 LinkedList의 HEAD값을 TAIL에 넣어준다.
  TAIL = tempHEAD;
}

void Top() { cout << TAIL->data << "\n"; }

void RandomInput(int numOfOuputs) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(1, 50);
  for (int i = 0; i < numOfOuputs; i++) Append(dis(gen));
}

int main() { return 0; }