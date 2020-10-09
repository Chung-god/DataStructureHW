#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int funcN;
int term;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.second < b.second;
}
vector<pair<int,int> > v1;
vector<pair<int,int> > v2;
int main(){
    cin>>funcN>>term;
    funcN--;
    while(term--){
        int Num,termN;
        cin>>Num>>termN;
        v1.push_back(make_pair(Num,termN));
    }
    sort(v1.begin(),v1.end(),cmp);

    for(int i = 0 ; i < v1.size(); i++){
        cout<<v1[i].first<<" "<<v1[i].second<<"\n";
    }


    while(funcN-- > 0){
        cin>>term;
        while(term--){
            int Num,termN;
            cin>>Num>>termN;
            
        }
    }
}