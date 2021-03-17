#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int sum=0;
    int b = 0;
    int sum2 = 0;
    vector<int> a;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> b;
        a.push_back(b);
        sum +=b;
    }

    sort(a.begin(), a.end());
    int count = 0;
    for(int i=n-1; i>=0; i--){
        sum2 += a[i];
        count++;
        
        if(sum2 > sum/2){
            
            break;
        }
        
    }
    printf("%d",  count);


    
}