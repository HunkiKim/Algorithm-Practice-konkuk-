#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int t,th,f,s;
    int sum = 0;
    int c256 , c32;
    
    scanf("%d%d%d%d",&t,&th,&f,&s);

    c256 = min(t,min(f,s));
    sum += c256 *256;
    t -= c256;
    c32 = min(t,th);
    sum += c32*32;
    printf("%d",sum);

    
}
