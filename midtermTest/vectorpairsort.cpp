#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second > p2.second) return true;
    else if(p1.second == p2.second){
        if(p1.first > p2.first) return true;
    }
    return false;
}

int main(){
    vector<pair<int,int> > v;
    v.push_back(make_pair(1,3));
    v.push_back(make_pair(5,3));
    v.push_back(make_pair(2,3));

    sort(v.begin(),v.end(),cmp);
    for(int i = 0 ;i < v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}