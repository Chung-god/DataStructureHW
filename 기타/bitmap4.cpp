#include <iostream>
using namespace std;

long long N;
long long temp = 0;
int MAT[64][64];

// get ith bit
bool getBit(long long num,int i){
    return((num & ((long long int)1 << i)) != 0);
}

//set ith bit
void setBit( int i){
    temp = temp | ((long long int)1<<i);
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    //input N and transpose bit first 
    for(int i = 0 ; i < 64; i++){
        cin>>N;    
        for(int j = 0; j < 64; j++){
            MAT[63-j][i] = getBit(N,j); 
        }
    }


 
    for(int i = 0 ; i < 64; i++){
        temp = 0;
        for(int j = 0; j < 64; j++){
            //if matrix value is 1 then set bit in temp
            if(MAT[i][j] == 1){ 
                setBit(63 - j);
            }
        }
        cout<<temp<<"\n"; //print num 
    }

}