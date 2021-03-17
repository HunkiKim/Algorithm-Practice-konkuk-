#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int o=0,t=0,th=0,f=0;
    int sum = 0;
    vector<int> g(100005);
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&g[i]);
        if(g[i]==1)
            o++;
        else if(g[i]==2)
            t++;
        else if(g[i]==3)
            th++;
        else
            f++;
    }
    
    sum += f;
    
    if(th>o){
        sum += th;
        th = 0;
        o=0;
    }else if(th==o){
        sum += th;
        th=0;
        o=0;
    }else{
        sum += th;
        o -= th;
        th = 0;
    }
    // th , o 는 이제 없
    // printf("%d\n",sum);
    sum = sum + t/2;
     
    t = t%2;
    // printf("%d\n",sum);
    if(o==1){
        sum += 1;
    }else if(o == 2){
        sum += 1;
    }else if(o == 0){
        if(t==1)
        sum+=1;

        sum += 0;
    }else{
        if(t==1){
        o-=2;
        sum +=1;
        }
        
        if(o%4 != 0 )
        sum+=1;
        
        sum += o/4;
    }

    
    
    printf("%d\n",sum);
    
}