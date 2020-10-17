#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<vector<int>> s;
stack<vector<int>>tempS;
stack<int> order;

int C,r,n;
int total = 0;
int main(){
    cin>>n>>r;
    int tmp = n;
    while(tmp--){
        int tmp;
        cin>>tmp;
        order.push(tmp);
        total += tmp;
    }
    cin>>C;
    C -= total;
    int rtmp = 0;
    int coeff = order.top();
    order.pop();

    for(int i =0; i <= C; i++ ){
        vector<int> tempV;
        int num = coeff * i;
        //cout<<"num : "<<num<<"\n";
        if(num == C){
            rtmp++; 
            if(rtmp == r){
                for(int i = 0; i < n-1; i++) cout<<"1 ";
                cout<<1+i;
                return 0;
            }
            break;
        }else if(num > C){
            continue;
        }else{
            tempV.push_back(num);
            tempV.push_back(i);
            s.push(tempV);
        }
    }

    while(true){
        int coeff = order.top();
        order.pop();
        int N = s.size();
        while(N--){
            vector<int> tempV = s.top();
            for(int i = 0; i <= C;i++){
                int num = coeff * i + tempV[0];
                cout<<"num : "<<num<<"\n";
                if(num == C){
                    rtmp++;
                    if(rtmp==r){
                        tempV.push_back(i);
                        for(int k = n; k > 0; k++){
                            if(!order.empty()) cout<<"1 ";
                            else{
                                cout<<tempV[k] + 1<<" ";
                            }
                        }
                        return 0;
                    }
                }else if(num > C){
                    continue;
                }else{
                    tempV.push_back(i);
                    tempV[0] += coeff * i;
                    tempS.push(tempV);
                }
            }
            s = tempS;
        }
    }
    
    // while(!s.empty()){
    //     vector<int> tempV = s.top();
    //     s.pop();
    //     for(int i = 0; i < tempV.size(); i++){
    //         cout<<tempV[i]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<"Hello,world!";
}