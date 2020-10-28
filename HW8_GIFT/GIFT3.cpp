#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int arr[21];
int n,r =0;
int C;
int rtmp = 0;

void findResult(int reminder,int index){
    if(index < 0) return;
    for(int i = 1; i <= reminder/arr[index]; i++){
        int temp = s.top() + arr[index];
        cout<<"temp : "<<temp<<"\n";
        s.pop();
        s.push(temp);
        if(reminder == temp){
            rtmp++;
            if(r == rtmp){
                cout<< "find";
            }
            return;
        }else if(reminder > temp){
            if(s.empty()) return;
            s.pop();
            findResult(reminder - temp, index-1);
        }else{
            s.pop();
            return;
        }
    }
}

int main(){
    cin>>n>>r;
    int time = 0;
    while(n>time){
        int temp;
        cin>>temp;
        arr[time] = temp;
        s.push(1);
    }
    cin>>C;
    for(int i = 0; i < n; i++){
        findResult(C,i+1);
    }
    
}