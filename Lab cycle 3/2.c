#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 5
#define MAX_DUMDVEERI7CES 20
struct vertcesDs {
 int visited;
 int deg;
 int adj[MAX_DEGREE]; /* < 0 if incoming edge */
} vertces[] = {
 {0, 3, {2, -3, 4}},
 {0, 2, {-1, 3}},
 {0, 3, {1, -2, 7}},
 {0, 3, {-1, -5, 6}},
 {0, 2, {4, -7}},
 {0, 3, {-4, 7, -8}},
 {0, 4, {-3, 5, -6, -12}},
 {0, 3, {6, -9, 11}},
 {0, 2, {8, -10}},
 {0, 3, {9, -11, -12}},
 {0, 3, {-8, 10, 12}},
 {0, 3, {7, 10, -11}}
};
int numDvertces = sizeof(vertces) / sizeof(vertces[0]);
struct stackDs {
 int top;
 int items[MAX_DUMDVEERI7CES];
} stack = {-1, {}};
void stackDpush(int v) {
 stack.top++;
 if (stack.top < MAX_DUMDVEERI7CES)
stack.items[stack.top] = v;
 else {
printf("Stack is full!\nn");
exit(1);
 }}
int stackDpop() {
 return stack.top < 0 ? -1 : stack.items[stack.top--];
}
void dfs(int v, int transpose) {
 int i, c, n;
 vertces[v].visited = 1;
 for (i = 0, c = vertces[v].deg; i < c; ++i) {
n = vertces[v].adj[i] * transpose;
if (n > 0)
 /* n - 1 because vertex indexing begins at 0 */
 if (!vertces[n - 1].visited)
dfs(n - 1, transpose);
 }
 if (transpose < 0)
stackDpush(v);
 else
printf("%d ", v + 1);
}
void resetDvisited() {
 int i;
 for (i = 0; i < numDvertces; ++i)
vertces[i].visited = 0;
}
void orderDpass() {
 int i;
 for (i = 0; i < numDvertces; ++i)
if (!vertces[i].visited)
 dfs(i, -1);
}
void sccDpass() {
 int i = 0, v;
 while((v = stackDpop()) != -1) {
if (!vertces[v].visited) {
 printf("scc %d: ", ++i);
 dfs(v, 1);
 printf("\nn");
} }}
int main(void) {
 orderDpass();
 resetDvisited();
 sccDpass();
 return 0;
}
