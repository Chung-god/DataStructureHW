#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long num;
    long long temp;
    int MAT[64][64];

    for(int i = 0; i < 64; i++){
        cin>>num;
        for(int j = 0; j < 64; j++){
            temp = ((num&(1<<j))!=0); 
            MAT[i][j] =temp;
        }
    }

    for(int i =0 ; i < 64; i++){
        for(int j = 0; j < 64; j++)
            cout<<MAT[i][j];
        cout<<"\n";
    }

    
    for(int i = 0; i < 64; i++){
        temp = 0;
        for(int j = 0; j < 64; j++){
            if(MAT[i][63-j] == 1){
                cout<<j;
                temp = temp | (1<<j);
            } 
        }
        cout<<temp<<"\n";
    }
}