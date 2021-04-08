#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int A[100005];
int main() {
  int n, i, R, L, a, b, ans, count, temp;
  ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);
  // a<b a가 작은 숫자 b가 큰 숫자
  // L 시작 Pointer R 이후 pointer
  L = 0;  //시작포인터이기떄문
  R = 1;  // 이후 포인터

  for (; R < n; R++) {  // 숫자가 달라지는 부분을 찾기 위함
    if (A[L] != A[R]) break;
    }
  if (R == n)
    count = R;
  else
    count = R + 1;

  a = min(A[L], A[R]);
  b = max(A[L], A[R]);
  while (R < n) {  // 뒤의 포인터가 끝까지 ..

    if (R == n - 1) break;

    while (R + 1 < n) {  // 수정할거 바로뒤가 바뀐게 아니라 344445 면 4 = 원래 R
                         // 이런식으로 수정
      if (A[R + 1] != a && A[R + 1] != b) {
        if (A[R + 1] < a) {
          b = a;
          a = A[R + 1];
          if (a == A[L] || b == A[L]) {
          } else {
            L = R;
          }
          ans = max(ans, count);
          R = R + 1;
          count = R - L + 1;
          break;
        } else {
          a = b;
          b = A[R + 1];
          if (a == A[L] || b == A[L]) {
          } else {
            L = R;
          }
          ans = max(ans, count);

          R = R + 1;
          count = R - L + 1;
          break;
        }
      } else {
        if (A[R] != A[R + 1] || A[L] != A[R]) L = R;
        count++;
        R++;
      }
    }
  }

  printf("%d", max(ans, count));
}
