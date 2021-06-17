#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* getNode(int data) {
  // data가 0이 아닐때 node반환
  if (data != 0) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
  }
  // 만약 data가 0이면 NULL반환
  return NULL;
}

Node* getCommonAncestor(Node* node, int f, int s) {
  if (node == NULL) return NULL;
  if (node->data > f && node->data > s)
    return getCommonAncestor(node->left, f, s);
  if (node->data < f && node->data < s)
    return getCommonAncestor(node->right, f, s);
  return node;
}

int main(void) {
  // 0 means null
  int input[7] = {6, 2, 8, 1, 3, 7, 9};

  Node* root = getNode(input[0]);
  root->left = getNode(input[1]);
  root->right = getNode(input[2]);
  root->left->left = getNode(input[3]);
  root->left->right = getNode(input[4]);
  root->right->left = getNode(input[5]);
  root->right->right = getNode(input[6]);

  int first = 0, second = 0;
  scanf("%d %d", &first, &second);
  Node* result = getCommonAncestor(root, first, second);
  printf("the common ancester of %d and %d is %d", first, second, result->data);
  return 0;
}
