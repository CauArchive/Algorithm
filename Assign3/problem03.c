#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* root;

Node* getNode(int data);
int BSTValidation(Node* root);

int main(void) {
  // 0 means null
  int input[7] = {8, 3, 9, 0, 0, 4, 7};
  root = getNode(input[0]);
  root->left = getNode(input[1]);
  root->right = getNode(input[2]);
  root->left->left = getNode(input[3]);
  root->left->right = getNode(input[4]);
  root->right->left = getNode(input[5]);
  root->right->right = getNode(input[6]);

  printf("The input is : ");
  for (int i = 0; i < 7; i++) printf("%d ", input[i]);
  printf("\n");
  if (BSTValidation(root))
    printf("it is bst");
  else
    printf("it is not bst");

  return 0;
}

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

int BSTValidation(Node* root) {
  if (root == NULL) return 1;
  if (root->left != NULL && root->left->data > root->data) return 0;
  if (root->right != NULL && root->right->data < root->data) return 0;
  if (!BSTValidation(root->left) || !BSTValidation(root->right)) return 0;
  return 1;
}
