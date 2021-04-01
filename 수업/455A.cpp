#include <stdio.h>
 
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
long long D[100005][2];  //
int C[100005];           // 바뀔떄 숫자의 카운트
long long A[100005];     // 케이스
long long V[100005];     // 바뀔떄 숫자 넣기
 
int main() {
  int i, j, c, n;
  long long ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  sort(A + 1, A + n + 1);
  A[0] = -1;
  for (i = 1, j = 0; i <= n; i++) {
    if (A[i] != A[i - 1]) {
      V[j] = A[i - 1];
      C[j] = c;
      c = 1;
      j++;
    } else {
      c++;
    }
  }
  V[j] = A[i - 1];
  C[j] = c;
  //마지막에 안바뀌면 넣어야됨
  D[0][0] = D[0][1] = 0;
  ans = 0;
  for (i = 1; i <= j; i++) {
    D[i][0] = max(D[i - 1][0], D[i - 1][1]);  //그전꺼에서 큰거
    if (V[i - 1] == V[i] - 1) {               //숫자가 바뀔때
      D[i][1] = D[i - 1][0] + V[i] * C[i];    //
    } else {
      D[i][1] = max(D[i - 1][0], D[i - 1][1]) + V[i] * C[i];
    }
    ans = max(ans, D[j][0]);
    ans = max(ans, D[j][1]);
  }
  printf("%lld\n", ans);
  return 0;
}