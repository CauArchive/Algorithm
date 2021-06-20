#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int a;
  int b;
  int w;
} node;

int parent[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int numOfVertex = 9;
int numOfEdge = 14;
// 각각의 a,b,c,d,e,f,g,h,i는 1~9로 치환됩니다
//      1,2,3,4,5,6,7,8,9
node input[14] = {{1, 2, 4}, {2, 3, 8},  {1, 8, 8}, {2, 8, 11}, {8, 9, 7},
                  {9, 3, 2}, {8, 7, 1},  {9, 7, 6}, {3, 4, 7},  {3, 6, 4},
                  {7, 6, 2}, {4, 6, 14}, {4, 5, 9}, {6, 5, 10}};

// Prim 알고리즘을 위한 전역변수들
int prim_start = 3;

int compare(const void* n1, const void* n2) {
  if (((node*)n1)->w > ((node*)n2)->w)
    return 1;
  else if (((node*)n1)->w < ((node*)n2)->w)
    return -1;
  else
    return 0;
}

int Find(int x) {
  if (x == parent[x])
    return x;
  else
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  int xParent = Find(x);
  int yParent = Find(y);
  parent[xParent] = yParent;
}

void print_node() {
  for (int i = 0; i < 14; i++) {
    printf("%d %d %d\n", input[i].a, input[i].b, input[i].w);
  }
}

int main(void) {
  // by Kruskal
  // 가중치에 따른 오름차순 정렬
  // qsort(input, sizeof(input) / sizeof(node), sizeof(node), compare);
  // int ans = 0, count = 0;
  // for (int i = 0; i < numOfEdge; i++) {
  //   int a = input[i].a;
  //   int b = input[i].b;
  //   int c = input[i].w;
  // 간선에 cycle이 생기는지 Union-Find 알고리즘을 통해 확인
  //   if (Find(a) == Find(b)) continue;
  // 간선 연결
  //   Union(a, b);
  //   ans += c;
  //   count++;
  //   if (count == numOfVertex - 1) break;
  // }
  // by Prim

  printf("answer is %d\n", ans);
  return 0;
}

/*
9 14
1 2 4
2 3 8
1 8 8
2 8 11
8 9 7
9 3 2
8 7 1
9 7 6
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
6 5 10
*/