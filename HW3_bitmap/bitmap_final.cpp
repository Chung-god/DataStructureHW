#include <iostream>
#define ll long long 
using namespace std;
int main(){
	cin.tie(NULL);
    ios::sync_with_stdio(false);
	ll N;
	ll temp = 0;
	int MAT[64][64];
    for(int i = 0 ; i < 64; i++){
        cin>>N;    
        for(int j = 0; j < 64; j++)
            MAT[63-j][i] = (N & ((ll)1 << j)) != 0;
    }

	for(int i = 0 ; i < 64; i++){
        temp = 0;
        for(int j = 0; j < 64; j++)
            if(MAT[i][j] == 1)
            	temp = temp | ((ll)1<<(63-j));              
        cout<<temp<<"\n";
    }
}
