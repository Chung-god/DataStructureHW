#include <iostream>
using namespace std;

int N,K;
bool sit[1000001];

int main(){
    cin>>N>>K;
    int t = K;
    while(t--){
        int temp;
        int front;
        int back;
        cin>>temp;

        if(t == K-1){
            cout<<temp<<" "<<temp<<" "<<temp<<"\n";
            sit[temp] = true;
            continue;
        }
        
        if(!sit[temp]){
            sit[temp] = true;
            int i;
            for(i = temp-1; ; i--){
                //cout<<i<<" ";
                if(i < 1) i = N;
                if(!sit[i]) continue;
                else{
                    front = i;
                    break;
                }
            }
            for(i = temp + 1; i != temp; i++){
                if(i >= N) i = 0;
                if(!sit[i]) continue;
                else{
                    back = i;
                    break;
                }
            }
            if(i == temp) back = temp;
            cout<<temp<<" "<<front<<" "<<back<<"\n";
        }else{
            sit[temp] = false;
        }
    }
}
