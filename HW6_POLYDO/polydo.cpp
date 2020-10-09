#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int funcN;
int c; //상수
int term; //항
vector<pair<int,int> > v;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin>>N;
    while(N--){
        cin>>funcN;
        while(funcN--){
            cin>>c>>term;
            bool NoTerm = false;
            for(int i = 0; i < v.size();i++){
                if(term==v[i].first){//항 비교
                    v[i].second += c;
                    if(v[i].second == 0)
                        v.erase(v.begin()+i);
                    NoTerm = true; //항이 있다.
                }
            }
            if(!NoTerm)
                v.push_back(make_pair(term,c));
        }
    }
    sort(v.begin(),v.end());

    if(v.empty()){
        cout<<"1\n0 0";
        return 0;
    }
    cout<<v.size()<<"\n";
    for(int i = v.size()-1; i >= 0;i--){
        if(v[i].second == 0) continue;
        cout<<v[i].second<<" "<<v[i].first<<"\n";
    }
}