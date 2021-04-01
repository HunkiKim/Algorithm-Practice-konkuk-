#include <stdio.h>
 
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
  int n, i, j;
  int D[200][2];
  int P[200][2];
  scanf("%d", &n);
  // 1.
  D[0][0] = D[0][1] = P[0][0] = P[0][1] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &D[i][0]);
    if (D[i][0] == 1)
      D[i][1] = 0;
    else if (D[i][0] == 0)
      D[i][1] = 1;
  }
 
  // 입력 완
  int ans = 0;
  int nf = 0;
  int yf = 0;
  for (i = 1; i <= n; i++) {
    nf += D[i][0];
    yf += D[i][1];
    P[i][0] = nf;
    P[i][1] = yf;
  }
  for (i = 0; i <= n - 1; i++) {
    for (j = i + 1; j <= n; j++) {
      ans = max(P[n][0] - P[j][0] + P[j][1] - P[i][1] + P[i][0], ans);
        }
  }
 
  if (n == 1)
    printf("%d", D[1][1]);
  else {
    if (P[n][0] == n)
      printf("%d", n - 1);
    else if (P[n][0] == ans) {
      printf("%d", P[n][0] - 1);
    } else
      printf("%d", ans);
  }
}