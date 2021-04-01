#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int D[4005][3];

// Dynamic Programming
int main() {
  int i, n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  int count = 0;
  D[0][0] = D[0][1] = D[0][2] = 0;  // 시작 길이는 1이상 이기떄문
  for (i = 1; i <= n; i++) {
    if (i - a > 0) {
      if (max(max(D[i - a][0], D[i - a][1]), D[i - a][2]) == 0)
        D[i][0] = 0;
      else
        D[i][0] = max(max(D[i - a][0], D[i - a][1]), D[i - a][2]) + 1;
    } else if (i - a == 0)
      D[i][0] = 1;
    else {
      D[i][0] = 0;
    }

    if (i - b > 0) {
      if (max(max(D[i - b][0], D[i - b][1]), D[i - b][2]) == 0)
        D[i][1] = 0;
      else
        D[i][1] = max(max(D[i - b][0], D[i - b][1]), D[i - b][2]) + 1;
    } else if (i - b == 0)
      D[i][1] = 1;
    else {
      D[i][1] = 0;
    }

    if (i - c > 0) {
      if (max(max(D[i - c][0], D[i - c][1]), D[i - c][2]) == 0)
        D[i][2] = 0;
      else
        D[i][2] = max(max(D[i - c][0], D[i - c][1]), D[i - c][2]) + 1;
    } else if (i - c == 0)
      D[i][2] = 1;
    else {
      D[i][2] = 0;
    }
  }
  int ans = max(max(D[i - 1][0], D[i - 1][1]), D[i - 1][2]);
  printf("%d", ans);
}