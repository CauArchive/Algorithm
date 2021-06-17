#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  // 0 - black, 1 - red
  int color;
  struct Node* parent;
  struct Node* left;
  struct Node* right;
} Node;

Node* root = NULL;

Node* getNode(int data, int color) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->color = color;
  temp->parent = NULL;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

Node* bst(Node* trav, Node* temp) {
  if (trav == NULL) return temp;
  if (temp->data < trav->data) {
    trav->left = bst(trav->left, temp);
    trav->left->parent = trav;
  } else if (temp->data > trav->data) {
    trav->right = bst(trav->right, temp);
    trav->right->parent = trav;
  }
  return trav;
}

void right_rotate(Node* temp) {
  Node* left = temp->left;
  temp->left = left->right;
  if (temp->left) temp->left->parent = temp;
  left->parent = temp->parent;
  if (!temp->parent)
    root = left;
  else if (temp == temp->parent->left)
    temp->parent->left = left;
  else
    temp->parent->right = left;
  left->right = temp;
  temp->parent = left;
}

void left_rotate(Node* temp) {
  Node* right = temp->right;
  temp->right = right->left;
  if (temp->right) temp->right->parent = temp;
  right->parent = temp->parent;
  if (!temp->parent)
    root = right;
  else if (temp == temp->parent->left)
    temp->parent->left = right;
  else
    temp->parent->right = right;
  right->left = temp;
  temp->parent = right;
}

void fixup(Node* root, Node* pt) {
  Node* parent_pt = NULL;
  Node* grand_parent_pt = NULL;

  while ((pt != root) && (pt->color != 0) && (pt->parent->color == 1)) {
    parent_pt = pt->parent;
    grand_parent_pt = pt->parent->parent;
    if (parent_pt == grand_parent_pt->left) {
      Node* uncle_pt = grand_parent_pt->right;
      if (uncle_pt != NULL && uncle_pt->color == 1) {
        grand_parent_pt->color = 1;
        parent_pt->color = 0;
        uncle_pt->color = 0;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->right) {
          left_rotate(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        right_rotate(grand_parent_pt);
        int t = parent_pt->color;
        parent_pt->color = grand_parent_pt->color;
        grand_parent_pt->color = t;
        pt = parent_pt;
      }
    } else {
      Node* uncle_pt = grand_parent_pt->left;
      if ((uncle_pt != NULL) && (uncle_pt->color == 1)) {
        grand_parent_pt->color = 1;
        parent_pt->color = 0;
        uncle_pt->color = 0;
        pt = grand_parent_pt;
      } else {
        if (pt == parent_pt->left) {
          right_rotate(parent_pt);
          pt = parent_pt;
          parent_pt = pt->parent;
        }
        left_rotate(grand_parent_pt);
        int t = parent_pt->color;
        parent_pt->color = grand_parent_pt->color;
        grand_parent_pt->color = t;
        pt = parent_pt;
      }
    }
  }
  root->color = 0;
}

void inorder(Node* trav) {
  if (trav == NULL) return;
  inorder(trav->left);
  printf("%d ", trav->data);
  inorder(trav->right);
}

int main(void) {
  int input[6] = {41, 38, 31, 12, 19, 8};

  for (int i = 0; i < 6; i++) {
    Node* temp = getNode(input[i], 1);
    root = bst(root, temp);
    fixup(root, temp);
  }
  inorder(root);
  return 0;
}
