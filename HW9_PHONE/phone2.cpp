#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

pair<int,int> maxPhone;
pair<int,int> minPhone;
stack<pair<int,int> > test;
vector<pair<int,int> > phoneV;
bool arr[1000001];
int N;
int main(){
    cin>>N;
    int MAX = 0;
    int MIN = 10000000;
    int time =0;
    int maxindex,minindex;
    while(N>time){
        int fit,price;
        cin>>fit>>price;
        phoneV.push_back(make_pair(fit,price));
        if(MIN > price){
            MIN = price;
            minPhone.first = fit;
            minPhone.second = price;  
            //minindex = time
        }
        if(MAX < fit){
            MAX = fit;
            maxPhone.first = fit;
            maxPhone.second = price;
            //maxindex = time;
        }
        arr[time++] = 1;
    }
    
    test.push(minPhone);
    test.push(maxPhone);
    while(!test.empty()){
        pair<int,int> tmp = test.top(); 
        test.pop();
        for(int i = 0; i <phoneV.size();i++){
            if(!arr[i]) continue;//이미 아웃된 건 넘어감
            if(phoneV[i].first < tmp.first && phoneV[i].second > tmp.second)
                arr[i] = false;
            else if(phoneV[i].first == tmp.first || phoneV[i].second == tmp.second) continue;
            else test.push(phoneV[i]);
        }
    }

    for(int i = 0; i < phoneV.size(); i++){
        if(arr[i]) cout<<i<<" ";
    }
    cout<<"hello";

}