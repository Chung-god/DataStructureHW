#include <iostream>
#include <bitset>
#include <string>
#define ll long long 
#define ull unsigned long long 
#define MAX 64

using namespace std;

bool tempArr[MAX] = {0,};
bool MAT[MAX][MAX];
ll num;


void makeMAT(int index,string n){
    for(int i = MAX-1; i >= 0; i--){
        MAT[i][index] = n[i] -'0';
        //cout<<MAX-i-1<<","<<index<<" = "<< n[i] - '0'<<"\n";
    }
}

void makeLL(int index){
    string temp;
    for(int i = 0;i < MAX; i++){
        temp += to_string(MAT[index][i]);
    }
    cout<<temp<<"\n";
    
    ll result;
    ll e = 1;
    if(temp[0] != '1 '){
        for(int i=temp.length()-1; i >= 0; i--){
            for(int j = 0; j < temp.length()-i-1;j++)
                e= e*2;
                if(temp[i]=='1')
                    result += e;
                e=1;
        }
    }
    
    cout<<result<<"\n";

}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    for(int i = 0; i < MAX; i++){
        cin>>num;
        //cout<<bitset<MAX>(num)<<"\n";
        makeMAT(i,bitset<MAX>(num).to_string());
    }
    for(int i =0; i < MAX;i++){
        for(int j = 0; j < MAX; j++){
            cout<<MAT[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    makeLL(61);

}