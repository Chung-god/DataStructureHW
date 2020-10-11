#include <iostream>
using namespace std;

long long N;

bool getBit(int num,int i){
    return((num & (1 << i)) != 0);
}

bool setBit(int num, int i){
    return num | (1<<i);
}


int main(){
    cin>>N;    
    for(int i = 0; i < 64; i++){
        cout<<getBit(N,i);
    }
}