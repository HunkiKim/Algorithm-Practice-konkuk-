#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

 
using namespace std;

int main(){
  int n = 0;
  int m = 0;
  int count = 0;
  int count2 = 0;
  vector<long long> p(100005);
  vector<long long> a(100005);
  p[0] = 0; a[0] = 0;
  scanf("%d",&n); scanf("%d",&m);
  for(int i=1; i<=n; i++){
      scanf("%lld", &a[i]);
  }
  for(int i=1; i<=n; i++){
      p[i] = p[i-1] + a[i];
  }

  for(int i=1; i<=n; i++){
      if(p[i] - p[count] == m){
          count2++;
      }
      if(count<n && i == n){
          count++;
          i=1;
      }
  }
printf("%d",count2);
  
}