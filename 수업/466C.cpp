#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
 
using namespace std;
 
int main(){
	vector<long long> p(1000005);
	vector<long long> a(1000005);
	vector<int> che(1000005);
	
	
	int n;
	p[0] = 0; a[0] = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	
	for(int i=1; i<=n; i++){
		p[i] = p[i-1] + a[i];
	}
	
	//prefix sum end
	if(p[n]%3 != 0){
		printf("0");
		return 0;
	}
	
	long long total3 = p[n]/3;
	long long count = 0;
	long long count2 = 0;
	if(p[1]==total3) count++;
	for(int i=2; i<n; i++){
		if(p[i]== total3*2){
			count2 +=count;
		}
		if(p[i] == total3){
			count++;
		}
		
		
	}
	
	
	printf("%lld", count2);
	return 0;
}