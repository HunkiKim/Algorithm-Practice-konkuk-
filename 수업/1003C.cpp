#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
   vector<double> p(1000005);
   vector<double> a(1000005);
   vector<int> che(1000005);
   
   int k;
   int n;
   p[0] = 0; a[0] = 0;
   scanf("%d", &n);
   scanf("%d", &k);
   for(int i=1; i<=n; i++){
      scanf("%lf", &a[i]);
   }
   
   for(int i=1; i<=n; i++){
      p[i] = p[i-1] + a[i];
    //   printf("%lf p\n", p[i]);
   }
   double Max = 0;
   double value = 0;
   int i = 0;
   while(1){
      
      value = (p[i+k] - p[i])/k;
    //   printf("%lf lf %lf p\n",value, p[i+k]);
      Max = max(Max,value);
      if(k==n){
         break;
      }
      if(k+i == n){
         k++;
         i=0;
         continue;
      }
      i++;
      
   }
   
   cout.precision(16);
   cout << Max << endl;
   return 0;
}