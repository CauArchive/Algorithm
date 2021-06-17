#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _node {
  int data;
  _node* next;
} Node;

Node *HEAD, *TAIL;
int numOfNodes;

bool Append(int data);
bool Insert(int idx, int data);
void Traverse();
bool Remove();
void Reverse();
void Top();
void RandomInput(int numOfOutputs);

#endif
