#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node *HEAD, *TAIL;
int numOfNodes;

int Append(int data);
int Insert(int idx, int data);
void Traverse();
int Remove(int idx);
void RemoveDuplicates();
void Reverse();
void Top();
void RandomInput(int numOfOutput);
int BSTValidation();

int main(void) {
  RandomInput(20);
  Traverse();
  RemoveDuplicates();
  Traverse();

  return 0;
}

int Append(int data) {
  Node* next = (Node*)malloc(sizeof(Node));
  next->data = data;
  next->next = NULL;
  if (HEAD == NULL) {
    HEAD = next;
    TAIL = HEAD;
  } else {
    TAIL->next = next;
    TAIL = TAIL->next;
  }
  numOfNodes++;
  return 1;
}

int Insert(int idx, int data) {
  if (idx < 0 || idx > numOfNodes) return 0;
  // 삽입할 노드
  Node* temp = (Node*)malloc(sizeof(Node));
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
  return 1;
}

void Traverse() {
  Node* temp = HEAD;
  for (int i = 0; i < numOfNodes; i++) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int Remove(int idx) {
  if (idx < 0 || idx > numOfNodes) return 0;
  Node* cur = HEAD;
  if (idx == 0) {
    HEAD = HEAD->next;
    free(cur);
  } else {
    Node* tmp;
    // 해당 위치 이전 노드로 이동
    for (int i = 0; i < idx - 1; i++) cur = cur->next;
    // 단 맨 마지막 노드를 없앨경우 tail을 이전 노드로 바꿔줘야함
    if (idx == numOfNodes - 1) TAIL = cur;
    tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
  }
  numOfNodes--;
  return 1;
}

// 랜덤하게 생성되는
void RemoveDuplicates() {
  int rangeOfElem = 50;
  int dupCheck[51] = {
      0,
  };
  int curIdx = 0;
  Node* temp = HEAD;
  while (temp != NULL) {
    if (dupCheck[temp->data]) {
      //이미 같은 값을 가진 node가 존재할 경우
      temp = temp->next;
      Remove(curIdx);
      continue;
    } else {
      //같은 값을 가진 노드가 없을 경우
      dupCheck[temp->data]++;
      temp = temp->next;
      curIdx++;
    }
  }
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

void Top() { printf("%d\n", TAIL->data); }

void RandomInput(int numOfOutput) {
  srand(time(NULL));
  for (int i = 0; i < numOfOutput; i++) Append(rand() % 50 + 1);
}