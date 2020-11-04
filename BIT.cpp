#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i <= 8192; i++){
        for(int j =0; j <= 8192; j++){
            if(i / j != 4) continue;
            if(i * j == 7,006,652){
                cout<<i<<" "<<j<<"\n";
            }
        }
    }
}
