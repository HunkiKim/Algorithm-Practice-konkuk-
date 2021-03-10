#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> s;
        int num = 0;
        int count = 0;
        for(int j=0; j<s.length(); j++){
            if(s.at(j) == 'O'){ 
                count++;
                num += count;
            }else if(s.at(j) == 'X'){
                count = 0;
            }else{
                return 0;
            }
        }
        v[i] = num;
    }

    for(int i=0; i<n; i++){
        cout << v[i] << endl;
    }
    return 0;
}
