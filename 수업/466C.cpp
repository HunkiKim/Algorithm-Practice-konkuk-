#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

 
using namespace std;
 
 int main(){
     //  합끼리의 3등분이 있는가.. 있다면 몇개?
    //설계 
    // prefix sum을 이용
    // prefix sum%3 == 0 이 되는게 몇개인지 
    int n = 0; //10^5까지 가능
    vector<long long> p(100005); //prefix sum들의 집합 
    vector<long long> a(100005); //원속
    vector<long long> s(100005); // p[i]*3의 모음
    scanf("%d", &n);
    p[0] = 0; a[0] = 0; //0은 초기화만
    for(int j=1; j<=n; j++){
        scanf("%lld", &a[j]);
    }
    
    for(int j=1; j<=n; j++){
        p[j] = p[j-1] + a[j]; // 그전까지의 prefixsum과 현재원소 
    }
    //prefix sum end

    if(p[n]%3 == 0){//일단 3으로 나누어 져야 구할 수 있음
        printf("0"); 
        return 0;
    }

    for(int i=1; i<n-1; i++){
        if(p[i]*3==p[n]){
        }
    }



 }