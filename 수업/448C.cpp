#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int stroke(vector<int> a, int i, int n, int count){
    
    int mheight = 1000000000;
    int mgasu = 0;
    int zerocount = 0;
    if(i==n)
        return count;
    else if(a[i-1]==0 && a[i]!=0 && a[i+1]==0){
        // printf("i : %d n : %d\n", i,n);
        return count+1;
    }
        
    
    int sero = 0;
    
    int nozerocount = 0;
    for(int j=i; j<n; j++){
        
        if(a[j]==0){
            // count = stroke(a,j+1,n,count);
            
            
        }else {
            sero++;
        }
        
        if(mheight>a[j]){
            mheight = min(mheight, a[j]);
            mgasu = 1;
        }
        else
        {  
            mgasu++;
        }
    }
    
    //mheight , mgasu complte
    
    if(mheight==0)
            return count;

    int zeroc = i;
    if(mheight>=mgasu){ // 세로
        for(int j=i; j<n; j++){
            // printf("sero : %d , i : %d - n : %d  a[%d] : %d\n",sero, i,n,j,a[j]);
            a[j]=0;
            
        }
        count += sero;
        // printf("m gasu :%d  count  : %d\n",mgasu,count);
    }else{//가로 
        
        for(int j=i; j<n; j++){
            
            a[j] = a[j]-mheight;
            // printf("a[%d] : %d, mheight : %d \n",j,a[j], mheight);
            if(a[j]==0){
                zeroc++;
                
            }
        }
        
        // printf("here  mheight  %d\n",mheight);
        count += mheight;
    //    printf("here complte count : %d\n", count);
        
        if(zeroc==n)
            return count;
        for(int j=i; j<n; j++){
            if(a[j]==0){
                // printf("one\n");
                count = stroke(a,i,j,count);
                // printf("two\n");
                count = stroke(a,j+1,n,count);
            }
            
            
        }
    }
       
    // printf("last\n");
    return count;
    
}


int main(){
    vector<int> a(6000);
    int n;
    int count = 0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    count = stroke(a,0,n,count);

    printf("%d",count);

}