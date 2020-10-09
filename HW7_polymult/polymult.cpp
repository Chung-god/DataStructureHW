#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,funcN;
int c;
int term;

class Poly{
private:
    vector<pair<int,int> > v;
public:
    void add(int term){
        int n,t;
        while (term--)
        {
            cin>>n>>t;
            bool NoTerm = false;
            for(int i = 0; i < v.size(); i++){
                if(t == v[i].first){
                    v[i].second += n;
                    if(v[i].second == 0)
                        v.erase(v.begin()+i);
                    NoTerm = true;
                }
            }
            if(!NoTerm)
                v.push_back(make_pair(t,n));
        }
        sort(v.begin(),v.end());
    }

    
    void show(){
        for(int i = v.size()-1; i >= 0;i--){
            if(v[i].second == 0) continue;
            cout<<v[i].second<<" "<<v[i].first<<"\n";
        }
    }
};

int main(){
    Poly poly;
    int N;
    cin >>N;
    
    while(N--){
        int funcTerm;
        cin>>funcTerm;
        poly.add(funcTerm);
    }
    poly.show();
}