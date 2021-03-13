#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

 
using namespace std;
 
int main() {
  int n = 0;
  int seg = 0;
  long long cup = 0;
  vector<long long> p(100005);
  vector<long long> a(100005);
  vector<long long> Min(100005);
  cin >> n;
 
  for (int i = 0; i < n; i++) {
  	int count = 0;
    
    p[0] = 0;
    scanf("%d", &seg);
    for (int j = 1; j <= seg; j++) {
      scanf("%lld", &a[j]);
    }
    for (int j = 1; j <= seg; j++) {  // prefix sum
      p[j] = p[j-1] +  a[j];
    }
    

    // here prefix sum complete
    // max p[seg] 
    // pre 1 , 2, .. until n-1  
    Min[0] = 0; // 기준이 되는 Min 값 넣어두기 
    for (int j=1; j<=seg; j++){
      Min[j] = min(Min[j-1],p[j]); 
    } // prefix sum 들 중 가장 작은 prefix sum 찾기
    int check = 0;
    int check2 = 0; // prefix sum중 0이 되는 값이 있다면 check를 해줌
    //이유는 Min 전체 == 전체를 방지하기 위해 
    for(int j=1; j<=seg; j++){
      if(p[j]==0){
          check2=1;
        }
      if(p[seg] <= p[j]-Min[j-1]){
        if(j == seg && p[seg] == p[j]-Min[j-1] && check2 == 1){
          //만약 최소 prefixsum이 0이라면 p[seg] == p[seg]가 되는데 
          //이때 중간에 p[j] 가 0이라면 Min[j] 또한 0이 될 수 있기 떄문에
          //p[j] == 0 일경우를 체크를 함으로써 p[j] - Min[j-1]이 전체가
          //아님을 입증 
          // 전체의 prefix sum이 아닌경우인데 끝에서 값이 일치하는경우
          // 체크를 해줌으로써 해결 
          check = 1;
          break; //중간에 Min값에 변동이 없었고 원소를 모두 더한 값과
          // 최대로 큰 prefix  sum 이 같다면 
        }else if(j == seg && p[seg] == p[j] -Min[j-1] && check2 == 0){
          //중간에 prefix sum이 0이 아닌데 prefix sum의 전체 값이 
          //일치한다면 전체를 계산했다는 의미
          break;
        }
        
        check = 1;
        break;
      }
      
    }
    
    //전체 다 더한게 있으므로
    if(check == 1){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
    
    // 가장 큰 p[i] 찾기 
	
  }

  return 0;
}
