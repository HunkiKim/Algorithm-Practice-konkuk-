#include <stdio.h>
#include <time.h>
 
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
long long ans = 0;
void divide(long long n, long long s, long long e, long long p, long long q) {
  // s는 시작길이 e는 끝길이 q는 입력범위 첫번째 p는 입력범위 마지막 n은 입력 값
 
  if (s > e || p > q) return;
  long long m = (s + e) / 2;  // 중간값
 
  if (m > q) {  //끝값보다 중간값이 더 크다면
    // printf("m > q\n");
    divide(n / 2, s, m - 1, p, q);
 
  } else if (m < p) {  // 시작값x이 중간값보다 크다면
    // printf("m < p\n");
    divide(n / 2, m + 1, e, p, q);
 
  } else {
    // p<=m<=q 라면
    ans += (n % 2);
    //중간값 더해주고
    divide(n / 2, s, m - 1, p, m - 1);  // 시작부터 중간아래
    divide(n / 2, m + 1, e, m + 1, q);  // 중간뒤부터 마지막까지
  }
  return;
}
 
int main() {
  clock_t start, finish;
  long long n, p, q;
 
  long long s = 1;
 
  scanf("%lld", &n);
  scanf("%lld", &p);
  scanf("%lld", &q);
 
  while (n >= s) {
    s <<= 1;  //길이
  }
 
  s -= 1;
  // printf("%lld \n", s);
  // s 는 길이
  divide(n, 1, s, p, q);
  printf("%lld", ans);
  return 0;
}
