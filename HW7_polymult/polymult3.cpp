#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > v;
vector<pair<int,int> > tempv;
int main(){
    int N;
    cin>>N;
    bool first = false;
    while(N--){
        int termN;
        cin>>termN;
        while(termN--){
            int n1,n2;//°è¼ö,Ç×
            cin>>n1>>n2;
            if(!first){
                v.push_back(make_pair(n1,n2));
                continue;
            }
            tempv.push_back(make_pair(n1,n2));
        }
        if(!first) first = true;
    }
}