#include <iostream>
#include <stack>
using namespace std;

void showAll(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

stack<int> prevstack;
stack<int> afterstack;
int numofarr[10000];
int n,r,C;
int main(){
    cin>>n>>r;
    int total = 0;
    while(n--){
        int temp;
        cin>>temp;
        prevstack.push(temp);
        total += temp;
    }
    cin>>C;
    C -= total;
    if(C < 0){
        cout<<"NONE";
    }

}


