#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
long long D[100005]; 
int A[100005]; // 입력
int V[100005]; //sorting 시 그번쨰의 값
int C[100005]; //5가 3개 10이 7 ..

int main(){
    int n, i, c,j;
    scanf("%d",&n);
    for(i = 1; i<=n; i++)
        scanf("%d",&A[i]);
    sort(A+1, A+n+1);
    A[0] = -1;
    for(i = 1, j = 0; i<=n; i++){
        if(A[i]!=A[i-1]){
            V[j] = A[i-1]; C[j] = c;
            c = 0;
        }else{

        }
    }
    return 0;
}